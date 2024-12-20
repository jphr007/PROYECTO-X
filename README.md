# PROYECTO-X
'use client'

import React, { useState, useEffect } from 'react'
import { Button } from "@/components/ui/button"
import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card"
import { Reel } from '@/components/reel'

const SYMBOLS = ['cherry', 'lemon', 'orange', 'grape', 'bell', 'seven']

export default function SlotMachine() {
  const [reels, setReels] = useState(['cherry', 'cherry', 'cherry'])
  const [balance, setBalance] = useState(100)
  const [message, setMessage] = useState('')
  const [isSpinning, setIsSpinning] = useState(false)

  const spin = () => {
    if (balance < 10) {
      setMessage('No tienes suficiente saldo para jugar.')
      return
    }

    setIsSpinning(true)
    setBalance(balance - 10)

    const spinDuration = 2000 // 2 seconds
    const spinInterval = 100 // Update every 100ms

    let spinsLeft = spinDuration / spinInterval
    const spinTimer = setInterval(() => {
      setReels(reels.map(() => SYMBOLS[Math.floor(Math.random() * SYMBOLS.length)]))
      spinsLeft--

      if (spinsLeft <= 0) {
        clearInterval(spinTimer)
        const finalReels = SYMBOLS.map(() => SYMBOLS[Math.floor(Math.random() * SYMBOLS.length)])
        setReels(finalReels)
        checkWin(finalReels)
        setIsSpinning(false)
      }
    }, spinInterval)
  }

  const checkWin = (newReels: string[]) => {
    if (newReels[0] === newReels[1] && newReels[1] === newReels[2]) {
      const winAmount = 50
      setBalance(prev => prev + winAmount)
      setMessage(`¡Ganaste ${winAmount} créditos!`)
    } else if (newReels[0] === newReels[1] || newReels[1] === newReels[2] || newReels[0] === newReels[2]) {
      const winAmount = 20
      setBalance(prev => prev + winAmount)
      setMessage(`¡Ganaste ${winAmount} créditos!`)
    } else {
      setMessage('Inténtalo de nuevo.')
    }
  }

  return (
    <div className="min-h-screen bg-gradient-to-b from-purple-600 to-blue-600 flex items-center justify-center p-4">
      <Card className="w-full max-w-md">
        <CardHeader>
          <CardTitle className="text-center text-2xl font-bold">Tragamonedas</CardTitle>
        </CardHeader>
        <CardContent>
          <div className="flex justify-center gap-2 mb-4">
            {reels.map((symbol, index) => (
              <Reel key={index} symbol={symbol} />
            ))}
          </div>
          <div className="text-center mb-4 text-xl font-semibold">Saldo: {balance} créditos</div>
          <Button 
            onClick={spin} 
            className="w-full mb-4 text-lg font-bold" 
            disabled={isSpinning || balance < 10}
          >
            {isSpinning ? 'Girando...' : 'Girar (10 créditos)'}
          </Button>
          <div className="text-center text-lg font-medium">{message}</div>
        </CardContent>
      </Card>
    </div>
  )
}


#lang racket

(define (pair x y)
  (lambda (m) (m x y)))
(define (first z)
  (z (lambda (x y) x))
  )
(define (second z)
  (z (lambda (x y) y))
  )

; test
;(define p (pair 3 4))
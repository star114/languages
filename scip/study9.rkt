#lang racket

; step 1
(define balance 100)
(define (withdraw amount)
  (if (>= balance amount)
      (begin (set! balance (- balance amount))
             balance)
      "Insufficient funds"))

;test
(withdraw 25)
; 75
(withdraw 25)
; 50
(withdraw 60)
; "Insufficient funds"

; step 2
(define new-withdraw
  (let ((balance 100))
    (lambda (amount)
      (if (>= balance amount)
          (begin (set! balance (- balance amount))
                 balance)
          "Insufficient funds"))))
;test
(new-withdraw 25)
; 75
(new-withdraw 25)
; 50
(new-withdraw 60)
; "Insufficient funds"

; step 3
(define (make-withdraw balance)
  <?>)

;test
(define W1 (make-withdraw 100))
(define W2 (make-withdraw 100))

(W1 50)
; 50
(W2 70)
; 30
(W2 40)
; "Insufficient funds"
(W1 40)
; 10

; step 4
(define (make-account balance)
  (define (withdraw amount)
    (if (>= balance amount)
        (begin (set! balance (- balance amount))
               balance)
        "Insufficient funds"))
  (define (deposit amount)
    <?>)
  (define (dispatch m)
    (cond ((eq? m 'withdraw) withdraw)
          ((eq? m 'deposit) deposit)
          (else (error "Unknown request -- MAKE_ACOUNT" m))))
  dispatch)

;test
(define acc (make-account 100))
((acc 'withdraw) 50)
;50
((acc 'withdraw) 60)
;"Insufficient funds"
((acc 'deposit) 40)
;90
((acc 'withdraw) 60)
;30

; prepare
(define (rand-update x)
  (let ((a 27)
        (b 26)
        (m 127))
    (modulo (+ (* a x) b) m)))
(define random-init 7)
(define rand
  (let ((x random-init))
    (lambda ()
      (set! x (rand-update x))
      x)))

; monte carlo
(define (monte-carlo trials experiment)
  (define (iter trials-remaining trials-passed)
    <?>
    )
  (iter trials 0))

(define (cesaro-test)
  <?>)

(define (estimate-pi trials)
  <?>)

;test
(estimate-pi 100)

 
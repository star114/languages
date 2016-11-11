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
  (lambda (amount)
    (if (>= balance amount)
        (begin (set! balance (- balance amount))
               balance)
        "Insufficient funds")))

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
    (set! balance (+ balance amount))
    balance)
  (define (dispatch m)
    (cond ((eq? m 'withdraw) withdraw)
          ((eq? m 'deposit) deposit)
          (else (error "Unknown request -- MAKE_ACOUNT" m))))
  dispatch)

(define acc (make-account 100))
((acc 'withdraw) 50)
;50
((acc 'withdraw) 60)
;"Insufficient funds"
((acc 'deposit) 40)
;90
((acc 'withdraw) 60)
;30

;3.1.2
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

;; rand-update에서는 다음에 random값을 얻기 위해 이전 값을 알고 있어야 한다.
;; rand에서는 내부에 상태를 변하면서 가지고 있으므로 쓰는 쪽에서는 아무것도 몰라도 된다.

(define (monte-carlo trials experiment)
  (define (iter trials-remaining trials-passed)
    (cond ((= trials-remaining 0) (/ trials-passed trials))
          ((experiment)
           (iter (- trials-remaining 1) (+ trials-passed 1)))
          (else
           (iter (- trials-remaining 1) trials-passed))))
  (iter trials 0))

(define (cesaro-test)
  (= (gcd (random 10000) (random 10000)) 1))

(define (estimate-pi trials)
  (sqrt (/ 6 (monte-carlo trials cesaro-test))))

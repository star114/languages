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

; hw1
(define make-monitored
  (let ((count 0))
    (lambda (function)
      (define (dispatch m)
        (cond ((eq? m 'how-many-calls?) count)
              ((eq? m 'reset-count) (begin (set! count 0) count))
              (else (begin (set! count (+ count 1))
                           (function m)))
              ))
    dispatch)
    )
  )
(define s (make-monitored sqrt))
(s 100)
; 10
(s 'how-many-calls?)
; 1
(s 'reset-count)
; 0
(s 36)
; 6
(s 64)
; 8
(s 'how-many-calls?)
; 2

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
  (= (gcd (rand) (rand)) 1))

(define (estimate-pi trials)
  (sqrt (/ 6 (monte-carlo trials cesaro-test))))

;; p297 - rand 사용 안하는 경우 - 모듈화가 전혀 안되어 있다.
(define (random-gcd-test trials initial-x)
  (define (iter trials-remaining trials-passed x)
    (let ((x1 (rand-update x)))
      (let ((x2 (rand-update x1)))
        (cond ((= trials-remaining 0)
               (/ trials-passed trials))
              ((= (gcd x1 x2) 1)
               (iter (- trials-remaining 1) (+ trials-passed 1) x2))
              (else
               (iter (- trials-remaining 1) trials-passed x2))))))
  (iter trials 0 initial-x))

(define (estimate-pi-2 trials)
  (sqrt (/ 6 (random-gcd-test trials random-init))))

;; ex 3.5
(define (random-in-range low high)
  (let ((range (- high low)))
    (+ low (random range))))
;; 갑자기 random 프로시저 등장.. ㅎㅎ

(define (make-experiment x1 x2 y1 y2)
  (lambda ()
    (let ((radius (/ (- x2 x1) 2.0)))
      (let ((center-x (+ x1 radius))
            (center-y (+ y1 radius))
            (x (random-in-range x1 x2))
            (y (random-in-range y1 y2)))
        (>= (sqr radius) (+ (sqr (- x center-x)) (sqr (- y center-y))))))))

(define (estimate-integration p x1 x2 y1 y2 trials)
  (let ((area (* 1.0 (- x2 x1) (- y2 y1))))
    (* (monte-carlo trials p) area)))
  
(define experiment (make-experiment 0 10 0 10))
(estimate-integration experiment 0 10 0 10 1000)
  
;  
;(define (estimate-integration x1 x2 y1 y2 trials)
;  (define (pred)
;    (let ((radius (/ (- x2 x1) 2.0)))
;      (let ((center-x (+ x1 radius))
;            (center-y (+ y1 radius))
;            (x (random-in-range x1 x2))
;            (y (random-in-range y1 y2)))
;        (>= (sqr radius) (+ (sqr (- x center-x)) (sqr (- y center-y)))))))
;  (let ((area (* 1.0 (- x2 x1) (- y2 y1))))
;    (* (monte-carlo trials pred) area)))
;; (estimate-integration 0 10 0 10 99)
;; 책에서는 estimate-integration 프로시저가 p, x1, x2, y1, y2, trials 를 받는다고 했는데..
;; 위에서는 p(predicate)를 내부에서 정의했음.

;; ex3.6
;; (rand 'generate) - 생성
;; ((rand 'reset) new-value) - 리셋하고 new-value에서 시작
(define rand-2
  (let ((x random-init))
    (lambda (m)
      (cond ((eq? m 'generate) (begin (set! x (rand-update x)) x))
            ((eq? m 'reset) (lambda (init)
                              (set! x init) ;;(rand-update init))
                              x))))))
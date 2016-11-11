#lang racket
;; 연습문제 

;; 비밀번호 설정할 수 있는 계좌
(define (make-account-pw balance password)
  (define (withdraw amount)
    (if (>= balance amount)
        (begin (set! balance (- balance amount))
               balance)
        "Insufficient funds"))
  (define (deposit amount)
    (set! balance (+ balance amount)) 
    balance)
  (define (match-password secret-password)
    (eq? password secret-password))
  (define (dispatch secret-password m)
    (if (match-password secret-password)
	(cond ((eq? m 'withdraw) withdraw)
	      ((eq? m 'deposit) deposit)
	      (else (error "Unknown request -- MAKE-ACCOUNT"
			   m)))
	(error "Incorrect Password")))
  dispatch)


(define (make-joint account account-password secret-password)
  (define (match-password pw)
    (eq? pw secret-password))
  (lambda (x m)
    (cond ((match-password x) (account account-password m))
           (else "Incorrect Password"))
    )
  )
  
;; test
(define paul-acc (make-account-pw 100 'secret-password))
((paul-acc 'secret-password 'withdraw) 40)
(define peter-acc
   (make-joint paul-acc 'secret-password 'joint-account-password))
((peter-acc 'joint-account-password 'withdraw) 40)
(define peterpaul-acc
   (make-joint paul-acc 'secret-password 'triple-joint-password))
((peterpaul-acc 'triple-joint-password 'withdraw) 40)
((peterpaul-acc 'secret-password 'withdraw) 40) ;; error

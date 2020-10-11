package ru.skt.passman.client

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Spinner
import android.widget.TextView

class MainActivity : AppCompatActivity() {
    private lateinit var spinner: Spinner
    private lateinit var name: TextView
    private lateinit var username: TextView
    private lateinit var password: TextView
    private var accounts: MutableList<Account> = mutableListOf()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        findViews()
        generateAccounts()
        showFirst()
    }

    private fun findViews(){
        spinner = findViewById(R.id.accountsSpinner)
        name = findViewById(R.id.accountValueTextView)
        username = findViewById(R.id.usernameValueTextView)
        password = findViewById(R.id.passwordValueTextView)
    }

    private fun generateAccounts(){
        accounts.clear()
        for(i in 0..4){
            accounts.add(Account("name${i}","username${i}","password${i}"))
        }
    }

    private fun show(account: Account){
        name.text = account.name
        username.text = account.username
        password.text = account.password
    }

    private fun showFirst(){
        show(accounts[spinner.selectedItemPosition])
    }
}
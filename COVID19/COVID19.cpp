void process() {
    sievePrime();
    cin >> n >> m;

    int i(0);
    while(n > 1) {
        while(i < m1 && n % snt[i]) {
            ++i;
        }

        if(i >= m1) {
            break;
        }

        while(n % snt[i] == 0) {
            n /= snt[i];
            ++a[i];
        }

        nt.push_back(i);
    }

    if(n > 1) {
        nt.push_back(m1);
        snt[m1++] = n;
    }

    i = 0;
    while(m > 1) {
        while(i < m1 && m % snt[i]) {
            ++i;
        }

        if(i >= m1) {
            break;
        }

        while(m % snt[i] == 0) {
            m /= snt[i];
            ++b[i];
        }
    }

    if(m > 1) {
        if(m % n == 0 && m / n == 1) {
            ++carry;
        } else {
            nt.push_back(m1);
            snt[m1++] = m;
        }
    }

    int ans(0);
    for (int &i : nt) {
        if(a[i] && !b[i]) {
            ans += a[i];
            a[i] = 0;
        }
    }

    int ntMult(0);

    for (int &i : nt) {
        if(a[i] && b[i] && a[i] < b[i]) {
            int d(0);
            for (int j = a[i]; j < b[i]; j *= 2, ++d);

            ntMult = max(ntMult, d);
        }
    }

    ll mult(1 << ntMult);
    for (int &i : nt) {
        if(a[i] && b[i]) {
            ll mult1(mult);

            while(mult1 > 1) {
                while(a[i] * mult1 > b[i]) {
                    --a[i], ++ans;
                }

                if(a[i] * mult1 < b[i]) {
                    ++a[i], --ans;
                }

                a[i] *= 2;
                mult1 /= 2;
            }

            ans += a[i] - b[i];
        }
    }

    cout << ans + ntMult;
}

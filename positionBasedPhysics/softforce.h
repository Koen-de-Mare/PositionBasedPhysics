#ifndef SOFTFORCE_H
#define SOFTFORCE_H

class worldstate;

class softforce {
    public:
        softforce(worldstate* newMyWorldState);
        virtual ~softforce();
        virtual void applyForce() =0;
    protected:
    private:
        worldstate* myWorldState;
};

#endif // SOFTFORCE_H

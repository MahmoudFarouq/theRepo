package com.os;

import java.util.Scanner;

class Interface {
    private Scanner input;
    private MemSim memSim;
    private int size;

    Interface(){ }

    void run(){
        input = new Scanner(System.in);
        getSize();
        memSim = new MemSim(size);
        showMenu();
    }

    private void showMenu(){
        System.out.println("Please select one of the below Options:");
        System.out.println("1) Allocation\n2) De-allocation\n3) Defragmentation\n4) Print Memory status\n5) Exit\n");
        int choice = input.nextInt();
        switch (choice){
            case 1: _allocate();        break;
            case 2: _deallocate();      break;
            case 3: _defragmentation(); break;
            case 4: _printStatus();     break;
            case 5:                     return;
            default:
                System.out.println( "Wrong Input, Retry.." );
                showMenu(); break;
        }
    }

    private void getSize(){
        System.out.print("Please Enter The Initial Size of Memory: ");
        size = input.nextInt();
    }

    private void _allocate(){
        System.out.println("Please Enter the Size of the partition: ");
        int pSize = input.nextInt();
        assert ( pSize >= size );
        System.out.println("Please Select the Status for Allocating: ");
        System.out.println("1) Best-Fit\n2) Worst-Fit\n3) First-Fit\n");
        int pPolicy = input.nextInt();
        POLICY policy;
        switch (pPolicy){
            case 1: policy = POLICY.BEST_FIT ; break;
            case 2: policy = POLICY.WORST_FIT; break;
            case 3: policy = POLICY.FIRST_FIT; break;
            default:
                System.out.println( "Wrong Input, Retry.." );
                _allocate(); return;
        }
        int result = memSim.Allocate(pSize, policy);
        switch (result){
            case -1:
                System.out.println( "Failed To allocate the requested Partition." );
                break;
            default:
                System.out.println( "Successful Operation." );
                System.out.println( "Partition allocated at address: "+result );
                break;
        }
        showMenu();
    }

    private void _deallocate(){
        System.out.println("Please Enter the Address of the partition: ");
        int pAddress = input.nextInt();
        assert ( pAddress >= size );
        int result = memSim.Deallocate(pAddress);
        switch (result){
            case -1: System.out.println( "Failed To Deallocate the requested Partition." ); break;
            default: System.out.println( "Successful Operation." )                        ; break;
        }
        showMenu();
    }

    private void _defragmentation(){
        System.out.println("Please Select the Case for Defragmentation: ");
        System.out.println("1) CASE-1\n2) CASE-2\n3) CASE-3\n");
        int pCase = input.nextInt();
        DEFRAGMENT_CASE d_case;
        switch (pCase){
            case 1: d_case = DEFRAGMENT_CASE.CASE_1 ; break;
            case 2: d_case = DEFRAGMENT_CASE.CASE_2; break;
            case 3: d_case = DEFRAGMENT_CASE.CASE_3; break;
            default:
                System.out.println( "Wrong Input, Retry.." );
                _allocate(); return;
        }
        memSim.Defragment(d_case);
        System.out.println( "Successful Operation." );
        showMenu();
    }

    private void _printStatus(){
        memSim.memoryStatus();
        showMenu();
    }

}

// �Ѿ������ת�����������
// �÷���convertcoor XXX x,y,z
// ����XXX��Ҫת����Ŀ¼������/d/fy/����/d/chenxiang/ ��ס���һ��/
// x,y,z�������������ĵ�ԭ���ľ������꣬����fy����0,0,0
// ��û�ж�ԭ�����ļ���������ת���������ļ�ȡ��.cto(�������Ǹ�cto������to������˼:)))
// ��������� ���ֻת��һ�Σ���Ȼ���鷳���ˡ�
// �Ժ����Ǽ��������ϵ��ʱ�򣬾���Ҫ�ã���������+������꣩���õ���������
// convertcoor.c

#include <ansi.h>
inherit F_CLEAN_UP;

int xcenter,ycenter,zcenter;
int do_convert(string arg);
int do_changecoor(string tofile,string line);

int main(object me,string arg)
//arg should be like this: "/d/fy/ 15,4,3" like this
{
    string *files;
    string dir;
    int i;
    int size;
    set_eval_limit(1); 
    seteuid(getuid());
    
    return notify_fail("
����������ת��������꣬�ƻ��Լ���
����4.0����ɴ�����������Ҫʹ�ô��������Ķ��޸Ĵ��ļ���ִ�С�\n");

    sscanf(arg,"%s %d,%d,%d",dir,xcenter,ycenter,zcenter);    
    
    files= get_dir(dir);
    
    for(i=0; i<sizeof(files); i++) 
    {
        size=sizeof(files[i]);
        if(files[i][(size-2)..size]==".c")
        {
            do_convert(dir+files[i]);
        }
    }
    return 1;
}

int do_convert(string arg)
{
    
    string tofile;
    string templine;
    int i;
        
    printf("now is convert file:%s\n",arg);    
    templine="";
    tofile=sprintf("%s%s",arg,"to");
    //log_file("static/convertcoor",arg+"\n");
    
    i=1; 
          
    do
    {           
        if( templine=efun::read_file(arg,i,1) )
        {
            do_changecoor(tofile,templine);
        }        
        else break;        
        i++;
    }while (1);
    return 1;
}

int do_changecoor(string tofile,string line)
{
    string x,y,z;
    string line2;
    int ix,iy,iz;
    int i;    
    
    //ȥ��table��;
    line2=replace_string(line,"\t","");
    //ȥ���ո�
    line2=replace_string(line2," ","");    
    
    
    x="set(\"coor/x\",";
    y="set(\"coor/y\",";
    z="set(\"coor/z\",";
    //is it x?
    if(strsrch(line2,x,1)!=-1)
    {
        sscanf(line2,x+"%d);",ix);                    
        line2=sprintf("\t%s%d);\n",x,ix-xcenter);
        line=line2;
    }
    //is it y?
    if(strsrch(line2,y,1)!=-1)
    {
        sscanf(line2,y+"%d);",iy);        
        line2=sprintf("\t%s%d);\n",y,iy-ycenter);
        line=line2;
    }

    //is it z
    if(strsrch(line2,z,1)!=-1)
    {
        sscanf(line2,z+"%d);",iz);        
        line2=sprintf("\t%s%d);\n",z,iz-zcenter);
        line=line2;
    }    
    efun::write_file(tofile,line,0);
}

// conpartner.c
// �����޸��ļ�����

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
// arg should be /d/baiyun/ ....
{
    string *files;
    int i;
    int size;
    set_eval_limit(1); 
    seteuid(getuid());
    
    return notify_fail("
����������ת��������꣬�ƻ��Լ���
����4.0����ɴ�����������Ҫʹ�ô��������Ķ��޸Ĵ��ļ���ִ�С�\n");

    
    if(!arg || arg=="") return notify_fail("��ʽ���ԣ�\n");
    
    files= get_dir(arg);
    
    for(i=0; i<sizeof(files); i++) 
    {
        size=sizeof(files[i]);
        if(files[i][(size-2)..size]==".c")
        {
            rm(arg+files[i]);
        }
    }
    files= get_dir(arg);
    
    for(i=0; i<sizeof(files); i++) 
    {
        size=sizeof(files[i]);
        if(files[i][(size-4)..size]==".cto")
        {
            rename(arg+files[i],arg+files[i][0..size-3]);
        }
    }
    return 1;
}

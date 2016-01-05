// mv.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        string src, dst;
 
        seteuid(geteuid(me));
        if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
        notify_fail("ָ���ʽ: mv <ԭ����> <Ŀ�굵��> \n");
 
        src = resolve_path(me->query("cwd"), src);
        dst = resolve_path(me->query("cwd"), dst);
 
        if( !rename(src, dst) )
                write("Ok.\n");
        else
                write("��û���㹻�Ķ�дȨ����\n");
        return 1;
}
 
int help(object me)
{
  write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	mv <ԭ����> <Ŀ�굵��>[0m
[0;1;37m����������������������������������������������������������������[0m   

��ָ��������޸�ĳ��������Ŀ¼���ơ�

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
 

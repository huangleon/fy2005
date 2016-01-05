// enforce.c
// the maxium 150 enforce is added for game balance. Silencer @1-1-2002

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int pts;

        if( !arg || (arg!="none" && !sscanf(arg, "%d", pts)) ) 
                return notify_fail("ָ���ʽ��enforce <ʹ�����������˵�>|none");

        if( !me->query_skill_mapped("force") )
                return notify_fail("������� enable һ���ڹ���\n");

        if( arg=="none" )
                me->delete("force_factor");
        else {
                if( pts < 0 || pts > (int)me->query_skill("force")/3)
                        return notify_fail("����ڹ��޷�������ô���������\n");
                if (pts >150)
                	return notify_fail("Enforce �������ֵ��150��\n");
                me->set("force_factor", pts);
        }

        write("Ok.\n");
        return 1;
}

int help (object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	enforce <ʹ�����������˵�>|none[0m
[0;1;37m����������������������������������������������������������������[0m   
 
���ָ������ָ��ÿ�λ��е���ʱ��Ҫ�������������˵С�
����Խ�ߣ��Ե��˵��˺�Խ��

enforce none ���ʾ�㲻ʹ�������� 

����2005����� enforceֵΪ150��
[0;1;37m����������������������������������������������������������������[0m   
HELP
        );
        return 1;
}
 

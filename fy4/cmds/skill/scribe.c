// scribe.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string spells, name, ob_name;
        object ob;

        // We might need to load new objects.
        seteuid(getuid());

        if( me->is_busy() )
                return notify_fail("( ����һ��������û����ɣ����ܻ�����\n");

        if( (int)me->query("sen") < 15 )
                return notify_fail("��ľ���̫���ˣ��޷�������\n");

        if( !arg
        ||      sscanf(arg, "%s on %s", name, ob_name)!= 2 )
                return notify_fail("ָ���ʽ��scribe <����> on <��Ʒ>\n");

        if( !objectp(ob = present(ob_name, me)) )
                return notify_fail("������û������������\n");

        if( stringp(spells = me->query_skill_mapped("scratching")) ) {
               if (me->is_fighting()) me->start_busy(1);
               return( SKILL_D(spells)->scribe_spell(me, ob, name) );         
        } 
        return notify_fail("�������� enable scratching ָ��ѡ����Ҫʹ�õķ���ϵ��\n");
}

int help (object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	scribe <��������> on <��Ʒ����>[0m
[0;1;37m����������������������������������������������������������������[0m   

�ڻ����õ��ҷ�ֽ(paper seal)��������Ʒ�ϻ�������ʹ����ͬ�ķ��䣬
���ڲ�ͬ����Ʒ��Ҳ�п����в�ͬ��Ч����

���㻭��֮ǰ����������� enable ָ����ָ����Ҫʹ�õ�����ϵ��

ע������������������(Ҫҧ����ָ����Ѫ��)���񣬻��ɵķ��������
	attachָ�������Ŀ�������ϡ�

[0;1;37m����������������������������������������������������������������[0m 
HELP
        );
        return 1;
}

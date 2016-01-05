// hp cmds (Mon  09-04-95)
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
string status_color(int current, int max);
 
int main(object me, string arg)
{
    object ob;
    mapping my;
 
    seteuid(getuid(me));
 
    if(!arg) ob = me;
    else if (wizardp(me))
    {
        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
    }
    else return notify_fail("ֻ�й���Ա�ܲ쿴���˵�״̬��\n");
    
    my = ob->query_entire_dbase();
    
    printf(" ����  �� %s%4d/ %4d %s(%3d%%)" NOR "    ʳ� %s%3d%%\n" NOR,
           status_color(my["gin"], my["eff_gin"]),	my["gin"],	my["eff_gin"],
           status_color(my["eff_gin"], my["max_gin"]),	my["eff_gin"] * 100 / my["max_gin"],
           status_color(my["food"], ob->max_food_capacity()),
           my["food"] * 100/ob->max_food_capacity()	
        );
    printf(" ��Ѫ  �� %s%4d/ %4d %s(%3d%%)" NOR "    ��ˮ�� %s%3d%%\n" NOR,
           status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
           status_color(my["eff_kee"], my["max_kee"]),     my["eff_kee"] * 100 / my["max_kee"],
           status_color(my["water"], ob->max_water_capacity()),
           my["water"] * 100/ob->max_water_capacity()
        );
    printf(" ����  �� %s%4d/ %4d %s(%3d%%)" HIW "    ���ۣ� %d\n" NOR,
           status_color(my["sen"], my["eff_sen"]), my["sen"], my["eff_sen"],
           status_color(my["eff_sen"], my["max_sen"]),     my["eff_sen"] * 100 / my["max_sen"],
           my["score"]
        );
    printf(" ����  �� %s%4d/ %4d (%4d)" HIR "    ɱ���� %d\n" NOR,
           status_color(my["atman"], my["max_atman"]),     my["atman"], my["max_atman"],
           my["atman_factor"],
           my["bellicosity"]
        );
    printf(" ����  �� %s%4d/ %4d (%4d)"  HIG "    Ǳ�ܣ� %d\n" NOR,
           status_color(my["force"], my["max_force"]),     my["force"], my["max_force"],
           my["force_factor"],
           (my["potential"] - my["learned_points"])
        );
    printf(" ����  �� %s%4d/ %4d (%4d)"HIM "    ���飺 %d\n" NOR,
           status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
           my["mana_factor"],
           my["combat_exp"]
        );

    return 1;
}
 
string status_color(int current, int max)
{
    int percent;
 
    if( max>0 ) percent = current * 100 / max;
    else percent = 100;
    if( percent > 100 ) return HIC;
    if( percent >= 90 ) return HIG;
    if( percent >= 60 ) return HIY;
    if( percent >= 30 ) return YEL;
    if( percent >= 10 ) return HIR;
    return RED;
}
 
int help(object me)
{
    write(@HELP
ָ���ʽ : hp
 
���ָ�������ʾ��(���)��һЩ����״̬��

 ����  ��  545/  545 (100%)    ʳ�  74%
 ��Ѫ  ��  838/  838 (100%)    ��ˮ��  74%
 ����  ��  544/  544 (100%)    ���ۣ� 104
 ����  ��  220/  220 (   0)    ɱ���� 156
 ����  ��  543/  543 (  34)    Ǳ�ܣ� 751
 ����  ��  350/  219 (   0)    ���飺 97775

see also : score
HELP
    );
    return 1;
}

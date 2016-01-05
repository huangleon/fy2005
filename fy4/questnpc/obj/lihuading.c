#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name( HIW "�������͸����" NOR, ({ "needle box","box" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","һ�����Ӳӵ�СԲͲ\n");
                set("material", "silver");
        }
        ::init_item();
}
void init()
{
	add_action("do_shoot","shoot");
}
int do_shoot(string arg)
{
	object ob;
	object me;
	string where;
	int dp;
	int damage;
	if (!arg) return notify_fail("��Ҫ��˭��\n");
//	if (query("used")) return notify_fail(this_object()->name()+"ֻ����һ��\n");
	me=this_player();
	if(userp(me))
		return notify_fail("�㲻֪��ʹ�õķ������޷����䡣\n");
    if ( me->query("combat_exp") < 50000 )
		return notify_fail("�㾭��̫���ˣ�û�а취����" + this_object()->name()+"�ķ����ؾ���\n");
    if( environment(me)->query("no_fight") ||
        environment(me)->query("no_magic") ||
        environment(me)->query("no_spells") 
	)
	return notify_fail("���ⲻ��͵Ϯ��\n");
    ob=present(arg,environment(me));
    if (!objectp(ob) || !living(ob)) return notify_fail(this_object()->name()+"ֻ�ܶԻ������ʹ��\n");
    if (!me->is_fighting(ob)) message_vision("$N��Цһ�����ӻ�������һ����������\n",me);
    message_vision("$N����$n���������е�"+this_object()->name()+"...\n",me,ob);
    message_vision(RED "��ϻ������������һƬ���⣮����...\n" NOR,me);
/*    
    where=file_name(environment(ob));
    if (!userp(ob) && where[0..6]=="/d/cave") {
    	message_vision(YEL"$N��Ц��:�����С��Ҳ�������������������Ū,��ү���ö��ˣ�\n"NOR,ob);
    	message_vision(YEL"$N������Σ���Ȼ�ڼ䲻�ݷ�֮�ʶ�������������꣡\n"NOR,ob);
    } else {		
*/
    if (ob->query_skill("perception")/10>random(32)) 
    	message_vision("$N������Σ���Ȼ�ڼ䲻�ݷ�֮�ʶ�������������꣡\n",ob);
    else {
    message_vision("�������$N���ϣ�һ������ʧ�ˡ�\n",ob);
    ob->receive_damage("kee", 0, me);
	dp=COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
    damage=800000-dp/3;
    damage/=100;
    if (damage<0) damage=0;
    ob->receive_wound("kee",damage,me);    
    ob->receive_wound("gin",damage,me);    
    ob->receive_wound("sen",damage,me);    
	}	
//    }	
    COMBAT_D->report_status(ob);                                         
    ob->kill_ob(me); 
  //  set("used",1);
//     me->start_busy(3);
    return 1;
}

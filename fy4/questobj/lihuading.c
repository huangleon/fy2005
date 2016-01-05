#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name( HIW "�����滨��" NOR, ({ "needle box","box" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
����ϻ���ߴ糤������������ü�Ϊ���£�ϻ�ӵ�
һ�����������м�ϸ����ף�ÿ�оſס�

ϻ�������������С׭��

���ؼ�Ѫ
�ջز���
����֮��
����֮��

�ұ߲�֪ʲô���½����������漸�У�

�۳ҽ������ݣ�
���η緭��ӿ��
�������滨��
��ȥ�ֺ�¶�ء�
˭�͡�˭�͡�
��������һ�Ρ�

�ƺ���һ�ס��������
LONG);
                set("material", "silver");
                set("no_split", 1);
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
	if (query("used")) return notify_fail(this_object()->name()+"�Ѿ������ˡ�\n");
	me=this_player();
    	if ( me->query("combat_exp") < 50000 )
		return notify_fail("�㾭��̫���ˣ�û�а취����" + this_object()->name()+"�ķ����ؾ���\n");
    	if( environment(me)->query("no_fight") || environment(me)->query("no_magic") || environment(me)->query("no_spells"))
		return notify_fail("���ⲻ��͵Ϯ��\n");
    	ob=present(arg,environment(me));
    	if (!objectp(ob) || !living(ob)) 
    		return notify_fail(this_object()->name()+"ֻ�ܶԻ������ʹ�á�\n");
    	
    	if (userp(me) && me!= ob)
	if (!COMBAT_D->legitimate_kill(me, ob)) {
		if (stringp(ob->query("NO_KILL")))
			return notify_fail(ob->query("NO_KILL"));
		if (stringp(ob->query("NO_PK")))
			return notify_fail(ob->query("NO_PK"));	
		else 
			return notify_fail("���޷��������ˡ�\n");
	}
	
    	message_vision(BLU"$N��Цһ�����ӻ�������һ����������\n"NOR,me);
    	if (ob!=me)
    		message_vision(HIW"$N����$n���������еı����滨�룬��ϻ������������һƬ���⡣��������\n",me,ob);
    	else {
    		message("vision",HIW""+me->name()+HIW"�����Լ����������еı����滨�룬��ϻ������������һƬ���⡣��������\n"NOR,environment(me),me);
    		tell_object(me,HIW"������Լ����������еı����滨�룬��ϻ������������һƬ���⡣��������\n"NOR);
    	}
    	    
    	where=file_name(environment(ob));
    	if (!userp(ob) && where[0..6]=="/d/cave") {
    		message_vision(YEL"$N��Ц��:�����С��Ҳ�������������������Ū,��ү���ö��ˣ�\n"NOR,ob);
    		message_vision(YEL"$N������Σ���Ȼ�ڼ䲻�ݷ�֮�ʶ�������������꣡\n\n"NOR,ob);
    	} else {		
    		if (ob->query_skill("perception")/10>random(22) || ob->query("no_shot")) {
    			if (me!=ob) message_vision("$N������Σ���Ȼ�ڼ䲻�ݷ�֮�ʶ�������������꣡\n\n",ob);
    			else {
    				message("vision",me->name()+"������Σ���Ȼ�ڼ䲻�ݷ�֮�ʶ�������������꣡\n\n",environment(me),me);
    				tell_object(me,"��������Σ���Ȼ�ڼ䲻�ݷ�֮�ʶ�������������꣡\n\n");
    			}	
    		}else {
    			message_vision(HIR"�������$N���ϣ�һ������ʧ�ˡ�\n\n"NOR,ob);
    			dp=COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
    		        damage=300000-dp; 
    			damage/=100;
    			damage=damage*2;  //add by ldb �����ؾ�¥ 
    			if (damage<0) damage=0;
    			ob->receive_wound("kee",damage,me);    
    			ob->receive_wound("gin",damage,me);    
    			ob->receive_wound("sen",damage,me);    
		}	
    	}	
    	COMBAT_D->report_status(ob);                                         
    	if (ob!=me)	ob->kill_ob(me); 
    	set("used",1);
    	if (me->query_busy()<3) me->start_busy(3);
    	return 1;
}

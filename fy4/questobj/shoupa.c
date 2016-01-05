#include <ansi.h>
#include <combat.h>
inherit ITEM;

void create()
{
    set_name(MAG"����������"NOR, ({ "handkerchief" }) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("long", "һ��ԼĪ�ĳ߼����İ׶��������Ľ��϶�����һ��컨���������Σ�ÿ��
���Զ�����һ�Ŵ���ɫ��Ҷ�ӣ�ӭ��΢�磬��ס�ض�����\n");
		set("desc_ext","shaking �Է�Ӣ������");
		}
   	::init_item();
}

void init()
{
	if(this_player()==environment())
	add_action("do_shake","shaking");
}

int do_shake(string arg)
{
	object ob;
	object me;
	string where;

	if (!arg) 
		return notify_fail("�����Ե�˭��\n"); 
	if (query("used")) 
		return notify_fail(this_object()->name()+"ֻ����һ�Ρ�\n");
	me=this_player();
	
	if( environment(me)->query("no_fight") || environment(me)->query("no_magic") 
		|| environment(me)->query("no_spells"))
		return notify_fail("���ⲻ��͵Ϯ��\n");
		
	ob=present(arg,environment(me));
	if (!objectp(ob) || !living(ob)|| ob->query("race")=="Ԫ��" ) 
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
	
	
	if (ob!=me)
		message_vision(GRN"\n$N��������һ���$n���˶����е�"+name()+GRN"��һ˿�������޵���������������\n"NOR,me,ob);
        else {
        	message("vision",GRN"\n"+me->name()+GRN"��������һ����Լ����˶����е�"+name()+GRN"��һ˿�������޵���������������\n"NOR,environment(me),me);
        	tell_object(me,GRN"\n����������һ����Լ����˶����е�"+name()+GRN"��һ˿�������޵���������������\n");
        }
        
    where=file_name(environment(ob));
    if (!userp(ob) && where[0..6]=="/d/cave") {
    	 message_vision(YEL"$N��Ц��:�����С��Ҳ�������������������Ū,��ү���ö��ˣ�\n"NOR,ob);
    	 message_vision(HIR"\n$N����$n���һ���������Ķ�������֪�߳�...\n"NOR,ob,me);
    	 ob->kill_ob(me);
    } else {          
		if (ob == me || random( me->query("cps")+me->query("int")) > random (ob->query("cps"))+random(ob->query("int"))
	    	&& random(me->query("combat_exp")*2)> ob->query("combat_exp")
	    	&& !ob->query("big_boss")  && !ob->query("real_boss") &&!ob->query("boss"))		{
	        	if (ob!=me)
	        		message_vision(MAG "\n\n$Nֻ������ǰ��ʰ�쵣�����΢����ת�˼���Ȧ�ӣ����ڵ��ϡ���\n"NOR,ob);
				else {
					message("vision",MAG "\n\n"+me->name()+MAG"ֻ������ǰ��ʰ�쵣�����΢����ת�˼���Ȧ�ӣ����ڵ��ϡ���\n"NOR,environment(me),me);
					tell_object(me,MAG "\n\n��ֻ������ǰ��ʰ�쵣�����΢����ת�˼���Ȧ�ӣ����ڵ��ϡ���\n"NOR);
				}
				ob->unconcious();
			}else	{
		        message_vision(CYN"\n\n$N��æ�����ڱǣ���ס��������ȥ������������\n"NOR,ob);
		        message_vision(HIR"\n$N����$n���һ���������Ķ�������֪�߳ܡ���\n"NOR,ob,me);
				ob->kill_ob(me);
			}
		}
	set("used",1);
	if (me->query_busy()<3) me->start_busy(3);
	return 1;
}

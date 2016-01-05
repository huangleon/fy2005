inherit NPC;
#include <ansi.h>
void create()
{
        set_name("����ؤ", ({ "lepra beggar" }) );
        set("gender", "����" );
        set("age", 28);
        set("long", "����һ�������ķ���ؤ�������ŧˮ�������ߣ�Ϊ�������������� 
�����һ�ǣ�����ս��������һϢ����֪��ʲô����������������죩�� \n");
        set("combat_exp", 200000);
        set("str", 10);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 20);
        set("chat_chance", 1);
		set("chat_msg", ({
                "����ؤ����������ֵ�����������ﷺ�Ű�ĭ��ɬɬ������\n",
        }) );
        setup();
        carry_object("obj/armor/cloth")->wear();
}


void init()
{
	add_action("do_heal","heal");
	add_action("do_decide","decide");
}

int do_decide(string arg)
{
	object wangshedan, zhuyeshedan, xiangweishedan;
	object me;
	me = this_player();
	if (!me->query_temp("��ɽ��/ι��ҩ"))
		return 0;
	if (arg != "not" && arg != "heal")
	{
		return notify_fail("��ֻ�ɾ��� heal �� not \n");
	}
	if (arg == "not")
	{
		me->delete_temp("��ɽ��/ι��ҩ");
		me->delete_temp("��ɽ��/�����");
		message_vision(HIW"$N���˶�ŵ�����һ��ҲȾ���������ô�죿���ˣ��������ˡ� \n"NOR,me);
		return 1;
	}else if (arg == "heal")
	{
		
		if (present("wang shedan",me) && present("zhuye shedan",me) && present("xiangwei shedan",me))
		{
			message_vision(
HIG"$n΢΢һЦ���׿�����������ߵ�������У�����һ�ɱ���֮���ӯȫ�� 
$n����$N��ǰ���������ߵ�����Һ�����ɵ�$N���С�����\n \n"NOR,this_object(),me);
			wangshedan =present("wang shedan",me);
			destruct(wangshedan);
			zhuyeshedan = present("zhuye shedan",me);
			destruct(zhuyeshedan);
			xiangweishedan = present("xiangwei shedan",me);
			destruct(xiangweishedan);
			call_out("healing",3,me);
			return 1;
			
		}else
		{
			return notify_fail("��û���㹻��ҩ�ģ�\n");
		}
	}
}

void bePrince(object me)
{
	if (me && environment(me) == environment(this_object()))
	{
		message_vision(
HIC"$N���ɵ�����һ���������Ǹղ����۵ķ���ؤ����һ˫��������˫���ƺ�
Ҫ�����Ķ�����ȥ��\n\n"NOR,me);
		message_vision(
HIC"���껺��վ����$N΢Ц������ϲ��λ"+RANK_D->query_respect(me)+"������ͨ��ɽ���ĵ�
һ����ˡ�\n˵�գ�ת����ȥ��\n\n"NOR,me);	
		message_vision(
HIC"$N������һ�㣬����������΢�����һ�ش�ˮ��΢Ц�оþò����԰Ρ���\n\n"NOR,me);
		destruct(this_object());
	}else
	{
		message_vision("$N����վ��ת����ȥ\n",this_object());
		destruct(this_object());
	}
	return;
}

void healing(object me)
{
	if (me && environment(me) == environment(this_object()))
	{
		me->delete_temp("��ɽ��/ι��ҩ");
		me->delete_temp("��ɽ��/�����");
		me->set("��ɽ��/�������",1);
		message_vision("������Ĺ���$N��������֪������������˫�ۡ�\n",this_object());
		//let him be a prince for ppl who have patience,giggle
		call_out("bePrince",10,me);
		this_object()->set("long","һ������޳���������������˫�������ꡣ\n");		
		if (!me->query("ɽ��/��ؤ����"))
			me->set("ɽ��/��ؤ����",1);
	}
	return;
}


int do_heal(string arg)
{
	object me;
	me = this_player();
	if (arg != "lepra beggar" && arg != "����ؤ")
	{
		return 0;
	}
	if (me->query_temp("��ɽ��/�����"))
	{
		if (present("wang shedan",me) && present("zhuye shedan",me) && present("xiangwei shedan",me))
		{
			message_vision(
HIR"$N���˿������૵���������˵����Ҫ�������ߵ�������Һ֮�У�Ȼ������ 
ι�����˷��ܴ�Ч���ҵ��Ǿ��벻�ȣ���decide heal or not��\n "NOR,me);
			//me->delete_temp("��ɽ��/�����");
			me->set_temp("��ɽ��/ι��ҩ",1);
		}else
			message_vision(
HIR"$n̾�˿�����˫ϥ��أ���ϸ���$N�Ĳ��飬˼���˰��죬�૵����������
��������˵����Ҫ�����������ߵ��ߵ�����ҩ��������������ȥ���ҡ��� \n"NOR,this_object(),me);
		//me->set_temp("��ɽ��/����ҩ");
	}else
	{
		message_vision(
WHT"$n��ԥ��һ�£�����$N�Ļ���񴯣�����ֱ��Ż�£���æ��ס�ڱǶ���һ�ߡ� \n"NOR,this_object(),me);
	}
	return 1; 
}
int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) + 
"��������һ�����кñ��ģ�");
        return 1;
}


int accept_fight(object me)
{
     tell_object(me,"��һ��ͬ���ĺò��ã�������Ҫ����Ү\n");
	 return 0;
}
 

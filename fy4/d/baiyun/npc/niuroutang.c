#include <ansi.h>
#include <command.h>
inherit NPC;

void create()
{
    	set_name("ţ����", ({ "niuroutang" }) );
    	set("title", HIB "�Ϻ�һ֦��"NOR);
	set("gender", "Ů��" );
    	set("age", 16);
    	set("per", 23);
		set("long", @LONG
һ���ظ��ܸߣ���֫��ϸ�����ȴ��С��Ů���ӣ��۾�����������飬
��˵���С��ȴ���Ϻ�С�����ˣ������е����͵Ĵ��ϴ��޲��Ժ���
���ȴ���(enjoy)Ϊ�١�
LONG
);
    	set("combat_exp", 50000);
   		set("attitude", "friendly");

   		setup();
    	carry_object("/d/fugui/npc/obj/w_skirt3")->wear();
}


int accept_fight(object me)
{
	command("say СŮ�����������Ķ��֣�");
	return 0;
}


int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) +
"�����Ϻ�С�۵�Զ��ϡ��������ţ��������\nȴ��ǧ��¥��Щӹ֬�׷ۡ�����\n");
    	if((int)obj->value() >= 5000) me->add_temp("marks/niuroutang",1);
        return 1;
}

void init()
{
	::init();
	add_action("do_enjoy","enjoy");
}

int do_enjoy()
{
	object me;
	object wo;
	object *inv;
	int maxgin,maxkee, maxsen;
	int i;
	me = this_player();
    	if((int)me->query_temp("marks/niuroutang") <=0)
	{
        	command("say ��Ӵ��������λ" + RANK_D->query_respect(me) +"������û������ô�ܺ����أ����ġ���");
        	tell_object(me,"���࣬�׻������Ӳ���ʮ������֤�����бꡣ\n");
		return 1;
	}
    	me->add_temp("marks/niuroutang",-1);
		message_vision(HIB"$N������Ц�ų�$n�߹�����ˮ�߰����֫Ť���Ų�������������\n"NOR,this_object(),me);


	if (REWARD_D->riddle_check(me,"����") == 3)
	{	
		tell_object(me,MAG"
ţ��������ָ������ļ�����������Ѩ֮�ϣ�������ߵ�Ц�����ĸζ������������ȥ��������\n");
		tell_object(me,HIR"
һ����ҵ�ʹ��Ϯ������Ļ��������ȥ��ģ�����ƺ��������˴ܽ����ӣ������һ��������\n");
		// annie ^^
		me->unconcious();
		message_vision(HIG"
һ���������£�ͷ��ѹ�Ŷ��ҵ����̶�Ȼ�ܽ����У����е���һ�ӣ��Ѿ���ס��$N�Ĳ��ӡ�
����������һ��$N��ʱ�ѳ�ţ�����Ļ�������������㱻����������
		
ţ����һ���������������Ѵ�������ս��Ʒ������Ӱ������\n"NOR,me);
		wo = find_object(AREA_BAIYUN"nujiao");
		if (!wo)
			wo = load_object(AREA_BAIYUN"nujiao");
		me->move(wo);
		me->revive();
	    REWARD_D->riddle_done(me,"����",20,1);
	    REWARD_D->riddle_set(me,"��ͼһ��",1);	// �����￪ʼ��ʽת�����riddle��
		return 1;
	}
	

	inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++)
        {
        if (inv[i]->query("no_drop") || inv[i]->query("owner")) continue;
		if(!DROP_CMD->do_drop(me, inv[i])) {
			destruct(inv[i]);
		}
	}
	
	me->unconcious();
	maxgin = (int)me->query("max_gin");
    maxkee = (int)me->query("max_kee");
    maxsen = (int)me->query("max_sen");
	me->set("eff_gin", maxgin);
	me->set("gin", maxgin);
        me->set("eff_kee", maxkee);
        me->set("kee", maxkee);
        me->set("eff_sen", maxsen);
        me->set("sen", maxsen);
        wo = new(__DIR__"obj/flower");
	wo->move(me);
	return 1;
}

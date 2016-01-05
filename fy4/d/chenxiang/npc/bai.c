inherit NPC;
#include <ansi.h>
void create()
{
        set_name("����", ({ "bai yujing", "bai", "yujing" }) );
        set("nickname", HIC"����"NOR);
        set("title", "��������");
        set("gender", "����" );
        set("age", 24);
 	set("per", 20);
	set("attitude","peaceful");
        set_temp("apply/damage",150);
        set_temp("apply/attack",200);

        set("long",
		"���ϰ��񾩣���ѥ�ӣ��ɽ��ʣ�������һ��ո�µ��·���\n"
	);

        set("combat_exp", 4000000);
        set("score", 200000);
        set("chat_chance", 1);
        set("chat_msg", ({
		"�����Ȼ��̾һ����ĬȻ���\n"	
        }) );
        set("inquiry",([
	        "Ԭ��ϼ"  :"Ԭ���ﾹ����������ĺ������ۣ���Ϊʲôƭ�ң�\n",
	        "yuan"  :"Ԭ���ﾹ����������ĺ������ۣ���Ϊʲôƭ�ң�\n",
	        "������"  :"���������˸��Ҷ����ᷢ�ܳ��������յĳ��������Ѳ�֪����η�������ܡ���\n",
	        "sword"  :"���������˸��Ҷ����ᷢ�ܳ��������յĳ��������Ѳ�֪����η�������ܡ���\n",
                ]) );

        set_skill("move", 100);
        set_skill("parry", 200);
        set_skill("dodge", 180);
        set_skill("force", 100);
	set_skill("unarmed", 180);
	set_skill("bai-quan",280);
        set_skill("sword",200);
	set_skill("qingpingsword",150);
        set_skill("qingpingforce",120);
        set_skill("chaos-steps",150);
        
	map_skill("force", "qingpingforce");
	map_skill("parry","qingpingsword");
        map_skill("sword","qingpingsword");
        map_skill("dodge","chaos-steps");
        map_skill("move","chaos-steps"); 
     	map_skill("unarmed","bai-quan"); 
        setup();
        carry_object("/d/chenxiang/npc/obj/newcloth")->wear();
        carry_object("/d/chenxiang/npc/obj/oldboots")->wear();
}

void init()
{
        object me;
        ::init();      
        if( interactive(me = this_player()) && !is_fighting() && !random(5)) 
        {
                call_out("greeting", 1, me);
        }
}


int greeting(object me)
{
	if (me && environment(me) == environment(this_object()))
    	message_vision("\n$N�����Ŵ��⡣����á�����á�����
$N��$n��������Ϊ��Ҫƭ�ң�Ԭ���﾿���ǰ��һ��Ǻ��ң�\n", this_object(), me);
        return 1;
}

int accept_object(object me, object obj)
{
	object bai, ob, sword;
	bai = this_object();
	
	if (F_LEVEL->get_level(me->query("combat_exp"))<30) {
		message_vision(CYN"$N���˿��㣬���ε�ҡ��ҡͷ��\n"NOR, bai);
		tell_object(me,"���������������Ҫ�ȼ�30��\n");
		return 0;
	}
	
	
	if( (string) obj->query("name") == "��ȸͼ" && obj->query("real"))
	{
		environment(me)->answer_notify(bai,0);
        message_vision(HIY "\n$N��$n��������Ϊ��һ�ſ�ȸͼ��������թ���˼�ɻ��������ڣ�\n��ɷ��֪��Ԭ���﾿���ǰ��һ��Ǻ��ң���answer love/hate��\n"NOR, this_object(), me);
		return 1;
	}
	else if( (string) obj->query("name") == HIG "������"NOR )
	{
        message_vision(HIW "\n$N������˫�֣���������ӹ�������������ͨ��һ����ˤ���ڵأ�����Ҳ�䵽���ϡ�\n��������ͣ������Լ��ı������ò����ˡ�\n"NOR, this_object());
		ob = present("floor", environment(this_object()));
		sword = new("/d/tieflag/obj/csword");
		sword->move(ob);
		return 1;
	}
	else
	{
	       	tell_object(me,"����˵�����ⲻ������Ҫ�ġ�\n");
        	return 0;
        }
}

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("���ɶ�", ({ "linxian" }) );
	set("title", HIR "���ֵ�һ����"NOR);
	set("gender", "Ů��" );
	set("age", 22);
	set("max_kee",20);
	set("long", @LONG
�������ݷ�������ü��һ˫��ϲ��ϲ����Ŀ��
�ж����������磬�о��ƽ�����ˮ��
LONG
);
	set("combat_exp", 100000);
	set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
		"���ɶ��������������ȹ������¶������˫������֬��ϸ�㡣\n",
		"���ɶ��ƺ����ȣ�������������ȣ����ѩ�׵ļ�ͦ�����ž����۵ס�\n",
		"���ɶ�����Ц��Ц�������۷߶���Ƴ�˰���һ�ۡ�\n",
        }) );
	set_skill("charm", 150);
	set("skill_public",1);
	setup();
	carry_object(__DIR__"obj/sskirt")->wear();
}


int accept_fight(object me)
{
	command("say СŮ�����������Ķ��֣�");
	return 0;
}

int recognize_apprentice(object ob)
{
    	if( (time()-ob->query_temp("marks/linxian_charm")) < 900)
        return 1;
		return 0;
}

int accept_object(object who, object ob)
{

	if (ob->query("id") == "huaqun")
	{
		message_vision("$N��$n����������лл������ҵ����ɢ���¡���\n",this_object(),who);
		who->set_temp("marks/linxian_charm",time());
		return 1;
	}
	return 0;
}

void reset(){
	if (!present("silver skirt",this_object()))
		carry_object(__DIR__"obj/sskirt")->wear();
}
	
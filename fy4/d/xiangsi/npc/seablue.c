// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("տ��", ({ "zhan lan", "lan","girl" }) );
	set("class","moon");
	set("gender", "Ů��" );
	set("age", 19);
	set("per", 36);
	set("int", 40);
	set("str", 24);
	set("score",-10000);
   	create_family("/", 3, "");
	set("title",CYN"���䵭��������"NOR);
	set("attitude", "friendly");
	set("long","һ���㷢���ƣ���ɢ��������Ů������ϥ����ͤ��֮�ϣ�һ����������
��Զ����ɽ�紵���������ŵı�ɴ���ɶ���¶��ɴ����֬������壬
�޳�Բ���˫�ȣ�������յ���֫������\n");
	set("chat_chance", 1);
	set("chat_msg", ({
		"տ�������������ǧ��ޣ��޼������ġ�ɽ�²�֪�����£�ˮ�������ǰ��������\n",
		"տ��̾����Ӣ��ĩ·�����˳�ĺ���������ճ�Թż������\n",
		"տ���ճյ�����Զ�����������֣����������飬��������˼������\n",
	}) );

	set("inquiry",([
		"�": 	"��������\n",
       	"����": 	"�����ΰ��Ѵ��飬İ�ϻ���ĺ��ɣ�����\n",
    	]) );

	set("no_arrest",1);
	set("skill_public",1);

	set_skill("spells",150);
	set_skill("heart-listening",200);
	map_skill("spells","heart-listening");

	set("NO_KILL","��һ����Ů����Ҳ�µ����֣�\n");

	setup();

	carry_object(__DIR__"obj/longskirt")->wear();
	carry_object(__DIR__"obj/jasmine")->wear();
	carry_object(__DIR__"obj/shoes")->wear();

}

void init()
{
	add_action("do_rape","rape");
}

int do_rape() // ȥ����!!!! ><"
{
	object me;
	me = this_player();
	message_vision(HIM"\n$N��Ұ�ް������$n����$n���·�˺ȥ������\n\n"NOR,me,this_object());
	message_vision(HIB"$nƫ��ͷ�����Ŀ���$Nһ�ۣ���������ڿ���΢΢һ����������д��һ�����ġ�
ǳ��ɫ��΢â�ڿ�����һ����û��$Nֻ����һ��Ī�����������������ײײ����ɽ����ˤȥ��\n\n"NOR,me,this_object());
	me->add_temp("block_msg/all",1);
	me->move("/obj/void");
	me->set_temp("last_damage_from","�����ᱡ������ˤ��ɽ�±�������ˡ�");
	me->die();	
	if (me->query_temp("block_msg/all")>=1)
	    me->add_temp("block_msg/all", -1);
	ccommand("heng");
	ccommand("hug zhan lan");
	return 1;
}




int recognize_apprentice(object ob)
{	
	object me = ob;

	if (ob->query("class") == "moon" 
		&& ob->query_temp("annie/seablue")
		&& ob->query_skill("chillblade",1)>=190 )
		return 1;

	if ( ob->query("class") == "moon"
		&& ob->query_skill("chillblade",1)>=190 )
	{
		message_vision(CYN"\n$n��ͷ����$Nһ�ۣ�����һЦ��\n$n��������ߵ�ͤ����\n"NOR,ob,this_object());
		ob->set_temp("annie/seablue",1);
		command ("say ����Ѧ�������£���������������˵˵�л���");
		return 1;
	}

	return notify_fail("տ�����ͷȥ��������Ҳ����\n");

}
/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/


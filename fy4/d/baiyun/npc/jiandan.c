// XXDER@FY3
inherit SMART_NPC;
#include <ansi.h>
void create()
{
    set_name("����" , ({ "jian dan","jian" }) );
    set("nickname",HIG"����Ȫ"NOR);
    set("long", "һϮ����ӭ�����ɢ���������裬�����������һ��������ĺ�«�������\n�����е��������˵ľ��㡣\n");
    set("age", 32);
    set("gender", "����" );
    create_family("���Ƴ�",1, "����");
    set("per",40);
    set("combat_exp", 3000000);
    set("chat_chance", 1);
    set("chat_msg", ({
        "�����������«���˼��ڣ��̿���ֽ���������ߣ����������������齣������\n
���ֱ����������´��ƣ���ɽ��ˮ�����գ�\n",
        "���������Ÿ裺�廨��ǧ���ã��������������ƣ����ͬ����ų\n",
	}) );
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     }) ); 		

	auto_npc_setup("wang",180,150,0,"/obj/weapon/","fighter_w","siqi-sword",1);
	setup();
    carry_object("/obj/armor/cloth")->wear();
    carry_object(__DIR__"obj/jadegourd");
    carry_object("/d/baiyun/npc/obj/zhaodan")->wield();
}


int accept_object(object me, object obj)
{
	if (!obj->query("annie/by_hy_draw"))
		return 0;
	if (REWARD_D->riddle_check(me,"��ͼһ��") != 3)
		return 0;

	ccommand("emote �������«���˼��ڣ��򿪻���ִ�һƳ�����٣������ӣ������������ж�Ҫ�����֮����á�");
	ccommand("emote ���ֽ��������뻳�У�Ҳ�����㣬�����轣�Ÿ裺�廨��ǧ���ã��������������ƣ����ͬ����ų");
	ccommand("emote ��Ц���������ִ��һʹ�����������İ����ģ����ʱ����֪���Ҷ����ǧ�����鰡��");
	ccommand("emote �������Σ�ͻȻ����鴤�����°�ĭ������˼��Ŀ������к�«��˻��������ʦ�֣��㡣���⡣���������͸���������������ô��");
	ccommand("emote ��ͨһ���Ե�����̨�ϡ�");

	set("long","��������ķ�����ʿ�����������ǲ��壬�ƺ����˾޶���
Ҫ�Ͻ�����������ѯ�ʡ�"YEL"���ν���"NOR"����\n");
	
	REWARD_D->riddle_set(me,"��ͼһ��",4);

	disable_player(HIR" <���Բ���>"NOR);
	set_temp("is_unconcious",1);
	set_temp("block_msg/all", 1);
	COMBAT_D->announce(this_object(), "unconcious");
	return 1;
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

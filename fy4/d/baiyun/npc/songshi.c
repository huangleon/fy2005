// XXDER@FY3

inherit SMART_NPC;
#include <ansi.h>

int leave();
void create()
{
    set_name("��ʵ" , ({ "song shi","song" }) );
    set("nickname",HIY"���ʵ"NOR);
    set("long", "էһ��ȥ���⺺�ӳ��³��㣬üĿ�ֺ�������ϸ�����������˾�������ʵ�Ǹ�\n����֮�ˡ�\n");
	set("attitude", "friendly");
    set("age", 32);
        set("gender", "����" );
        create_family("���Ƴ�",1, "����");
    set("per",40);
    set("combat_exp", 5500000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "��ʵ���ź��ӳ������Σ���Ȼ˫üһ��������һ�ţ��������˿�����\n",
        "��ʵ��ü΢�壬��̾һ������һ�ֽ����н٣����й�����г������ε��ƽ⣿\n",
	}) );
          set("inquiry",  ([
				"���ν���" :  (: leave :),
        ]) );

   	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
     }) ); 		

	auto_npc_setup("wang",200,180,1,"/obj/weapon/","fighter_w","qiusheng-blade",1);
   	setup();
    carry_object("/obj/armor/cloth")->wear();
    if (!random(10)) carry_object(BOOKS"blade_75");
}


int leave()
{
	object room = load_object("/d/baiyun/dragonplace");
	int i = REWARD_D->riddle_check(this_player(),"��ͼһ��");
	if ( i !=4 && i != 5 && i != 6)
		return 0;
	
	if (is_fighting())
	{
		tell_object(this_player(),name()+"��æ���˲���������\n");
		return 1;
	}
	if (environment() == room)
		return 0;
	delete("chat_msg");
	message_vision(WHT"$N��ŭ����Ҷ�³ǰ�Ҷ�³ǣ����μ�������ȥ������Ī�����������ɾ������µ�һ��ô��\n$N�������ݣ��·�����һ�������ȥ��\n"NOR, this_object());
	move(room);
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

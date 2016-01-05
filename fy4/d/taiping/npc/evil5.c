#include <ansi.h>
#include <command.h>
inherit SMART_NPC;

void create()
{
        set_name("��¥��ħ", ({ "evil" }) );
         set("title",HIR"ʮ����ħ֮"NOR);
        set("age", 400);
        set("long", "����ʮ�ص���ħ����ʽ��������ħ�������еİ��˰��ޣ��еķ��˷��ޣ��е���״
���ˣ�ȴ�����ˣ��е���״���ޣ�ȴƫƫ��һ�����ġ����У����У��һ��У�����
�У�û��һ���ط���������Щ��ħ����\n");
        set("attitude", "aggressive");
 	set("combat_exp", 8000000);
	
	set("max_atman", 600);
	set("atman", 600);
	set("max_mana", 600);
	set("mana", 600);
	set("max_force",1500);
	set("force",1500);
	set("force_factor",130);

	set("str",40);
	set("cor", 40);
	set("cps", 40);
	set("agi",40);
	set("fle",40);
	
	set("resistance/gin",30);
	set("resistance/kee",30);
	set("resistance/sen",30);
	set("statue",0);
	
	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(50) :),
        }) );
	
	
	auto_npc_setup("xuebin",250,200,0,"/obj/weapon/","fighter_w","shortsong-blade",1);
	setup();
	carry_object(__DIR__"obj/mblade")->wield();
}




void die(){
	object me,owner,ob;
	
	ob=this_object();
	
	message_vision(HIR"\nһ�ɺ�������$N����һ��ʯ��,һ�������ˡ�\n"NOR, this_object());
	ob->start_busy(10);
	ob->set("statue",1);
	call_out("reborn",20);
	this_object()->full_me();
//	"/cmds/imm/full"->main(this_object(),"");
	ob->set("resistance/kee",100);
	ob->set("resistance/gin",100);
	ob->set("resistance/sen",100);
	ob->remove_all_killer();
	
}

int reborn(){
	object ob;
	
	ob=this_object();
	message_vision(HIR"һת�۵Ĺ���,�������ۣ�ʯ�������ֻ������\n"NOR,ob);
	ob->set("resistance/kee",30);
	ob->set("resistance/gin",30);
	ob->set("resistance/sen",30);
	ob->set("statue",0);
	ob->stop_busy();
	ob->move(environment(ob));
	return 1;
}
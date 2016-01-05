inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();

void create()
{
		object weapon;
        set_name("���ʿ", ({ "ghost taoist","ghost","taoist"}) );
        set("title",CYN"Թ�����"NOR);
        set("gender", "����" );
    
	set("real_boss",1);
	set("no_arrest",1);


		set("chat_chance", 1);
		set("chat_msg", ({
				"���ʿ�૵����Һޡ����Һް�����\n",
				"���ʿ�૵�����Ů������Ů����\n",
				"���ʿ�૵���ɽ�ϡ���ѩ������\n",
		}) );

        set("age", 54);

        set("attitude","friendly");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
//                (: smart_fight() :),
             }) );

        set("combat_exp", 6000000);
		set_temp("apply/haste",200);
		set_temp("apply/damage",200);
		set_temp("apply/attack",600);
    
        set_skill("spells", 75);
        set_skill("perception", 75);
        
		set("skill_public",1);
        
		setup();

	weapon = new("/obj/armor/cloth");
	weapon->set_name(HIR BLK"���ò���"NOR, ({ "cloth" }));
	weapon->move(this_object());
	weapon->wear();
}


int recognize_apprentice(object ob)
{
        if (!ob->query("free_learn/advanced_spells_perception"))
        {
                message_vision("���ʿ���ŲҰ׵������ӣ��૵���ɱ����ɱ�����������������𡭡�\n\n",ob);
                return 0;
        }
    return 1;
}



int is_ghost() { return 1; }

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/


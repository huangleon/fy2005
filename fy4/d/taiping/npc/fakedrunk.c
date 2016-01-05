#include <ansi.h>
#include <command.h>

inherit SMART_NPC;
void do_drink();

void create()
{

	set_name("��",({"drunk"}));
	set("age",37);
	set("combat_exp", 5000000);
        	
	set("pursuer", 1);
	set("marks/parrot_killer",1);

        set("death_msg",CYN"\n$N˵�����ˣ��ܵ������ٶ���ʲô�á��� \n"NOR);
        set("chat_chance",1);
        set("chat_msg", ({
        	(: do_drink :), }) 
        );
        set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"\nɱ��˵������ʲô�¶����ܣ�ֻ��ɱ�ˣ�����\n",
        ]) ); 
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(30) :),    
        }) );
        
    	
		auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","sharen-sword",1);
		set_skill("move",400);
		setup();
		carry_object("/obj/armor/cloth")->wear();
		carry_object(AREA_FY"npc/obj/killersword")->wield();
}


void init(){
	::init();
	add_action("do_look", "look");
}


int do_look(string arg) {
	if(arg == "drunk"){
		write("һ��ҡͷ���Եĺ��ӣ���Ȼ�Ǻȶ��ˡ�\n");
		write("��������Լ��ʮ���ꡣ\n");
		write("��Ӣ��������ò���˰���\n");
		write("�����Ĳ��ֲ��ݣ��书����������"+HIB"����С��"NOR+"�������ƺ����ᡣ\n");
		write("������"+HIG"���ϲ���˿���˺ۡ�\n"NOR);
		write("��������(Cloth)\n");
		return 1;
	}
	return 0;
}

 
void do_drink()
{
    object *list, ob;
    int i, can_drink;
    if ((int)this_object()->query("water") >= 380) return;
    list = all_inventory(this_object());
    i = sizeof(list);
    can_drink = 0;
    while (i--) {
        if ((string)list[i]->query("liquid/type") == "alcohol") {
            ob = list[i];
            can_drink = 1;
        }
    }
    if (can_drink) {
        command("drink "+(string)ob->query("id"));
        if ((int)ob->query("liquid/remaining") == 0)
            command("drop wineskin");
    }
    else {
        command("sigh");
        command("say ��..... ���Ҿ�....");
    }
    return;
}
 
int accept_object(object who, object ob)
{
    if ((string)ob->query("liquid/type")=="alcohol") {
        if ((int)ob->query("liquid/remaining") == 0) {
            command("shake");
            command("say �յ��Ҳ�Ҫ...");
            return 0;
        }
        else {
            command("smile");
            command("say ��л!");
            return 1;
        }
    }
    else return 0;
}
 
void die() {
	
	object me, ob, owner;
	ob=this_object();
	
	if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
	
	if (me)
		me->set("marks/parrot/����",1);
	
	::die();
}


int heal_up()
{
	if(environment() && !is_fighting() 
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
//		command("say ok");
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}


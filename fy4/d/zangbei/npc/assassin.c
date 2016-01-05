#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;

int do_shoot(object ob);

void create()
{
    	set_name("����",({"trader"}));
	set("title","����һϢ");

   	set("long","
��ȫ���Ƥ�����ѱ�ɹ�ڣ��촽Ҳɹ���ˣ��۾���ϰ��ţ�������۰�
ȴ�ѷֲ����ˣ���������������ɵĶ�����\n");
     	set("gender","����");
    	set("age",32);
    	set("group","assassin"); 	
    	
    	set("kee",8000);
    	set("max_kee",8000);
    	set("eff_kee",8000);
    	set("NO_KILL","�����Ѿ�������ˣ�����ô�������֣�\n");
	
    	set("combat_exp",2000000);  
    	
		set("chat_chance",1);
    	set("chat_msg",({
		"���̲����ţ������ţ���ˮ����ˮ������\n",
    	"����������̧���֣���Զ��ָ��ָ��������ץסͷ����һ����ɫ�򾪾��Ť
��������Ҳ���ø�������\n",

    	}) ); 
    	  	
    	set("death_msg",CYN"\n
$Nȫ������һ�ţ�����ȴ������������˻���е�������ɱ���Ұɣ�
û��ϵ����������Ҳ����ģ����ڹ��Ź��ϵ����㣬�ٺ������ʡ���\n"NOR);  	
    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
 	
		auto_npc_setup("wang",150,150,0,"/obj/weapon/","fighter_u","wolf-strike",1);
		setup();    
}

void init(){
	::init();
	add_action("do_look", "look");
}

int do_look(string arg) {
	if(arg == "trader"){
		write("
��ȫ���Ƥ�����ѱ�ɹ�ڣ��촽Ҳɹ���ˣ��۾���ϰ��ţ�������۰�
ȴ�ѷֲ����ˣ���������������ɵĶ�����
��������Լ��ʮ���ꡣ
��������棬�������ٷ硣\n");
		write("��"CYN"���˾�����������"NOR"���书����������"BLU"��������"NOR"�������ƺ����ᡣ
��"HIR"��Ѫ��ֹ������ɢ�ң��Ѿ���������·��"NOR"��
���������塣\n");
		return 1;
	}
	return 0;
}


int accept_object(object who, object ob)
{
    	object tietong;
    	if (ob->query("liquid/type")=="alcohol" || ob->query("liquid/type")=="water") {
        	if ((int)ob->query("liquid/remaining") == 0) {
            		command("shake");
            		command("say ��ˮ����ˮ������");
            		return 0;
        	}
            	else {
	            	command("smile");
	            	command("say ��л!");
	            	ob->move(this_object());
	            	command("drink "+ob->query("id"));
	            	ob->move(this_player());
	            	ob->stop_busy();
	            	if (!tietong=present("box",this_object())){
	            		tietong= new(__DIR__"obj/tietong");
	            		tietong->move(this_object());
	            	}
	            	this_object()->set("name","�̿�");
	            	set("chat_chance",0);
	            	delete("NO_KILL");
	            	do_shoot(who);
	            	kill_ob(who);
	            	return 1;
        	}
    	}
    	else 
    		return 0;
}

int do_shoot(object ob)
{
	
	object me;
	string where;
	int dp, damage;
	
	me = this_object();
		
	if (!present(ob,environment(me)))
		return notify_fail("���û����ˡ�\n");
		
	message_vision(HIB"˵ʱ����ʱ�죬ͻ��������$Nһ���֣�ʮ�����ڹ��ָ������$n��ȥ������\n"NOR,me,ob);
    	    	    
    	if (ob->query_skill("perception")/10>random(22)) {
    		message_vision("$N������Σ���Ȼ�ڼ䲻�ݷ�֮�ʶ�����ⰵ����\n\n",ob);
    	}else {
		message_vision(HIB"�������$N���ϣ�һ������ʧ�ˡ�\n\n"NOR,ob);
		dp=COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
		damage=600000-dp;
		damage/=100;
		if (damage<0) damage=0;
		ob->receive_wound("kee",damage,me);    
		ob->receive_wound("gin",damage,me);    
		ob->receive_wound("sen",damage,me);    
	}	
    		
    	COMBAT_D->report_status(ob);                                         
    	ob->kill_ob(me); 
    	set("used",1);
    	me->start_busy(3);
    	if (ob->query("combat_exp")< 20000)
    		command("say �ϵ��ˣ��Ǵ��ף�����");
    		command("faint trader");
    	return 1;
}


void die(){
	environment(this_object())->set("long", @LONG
ɳ�𲢲���ת��ɳ�𣬾��Ƽ�һ���ˣ������ֱ�Ѳ��������ˣ�������һֻ
�����ڻ��ϣ��챻�����˵�����������ر��˶��ڵ��ϣ��������ף�������ϣ�
������ţƤ��ţƤ������ʪ�ģ���̫��ɹǬ�ᣬ��Խ��Խ����ֱǶ�����������
�Ѿ������׵׵����ˣ���û��һ˿������
LONG
        );
        ::die();
}
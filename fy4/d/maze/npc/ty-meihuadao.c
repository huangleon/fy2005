#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("÷����",({"meihuadao","dao"}));
	set("title",MAG"ǧ�滨��"NOR);
   	set("long","������������һ�Ų��ڷ�ɫ��ɴ����������ֳ�����֮ɫ������֮�У��׹�է�֡���\n");
     	set("gender","Ů��");
     	set("age",20);
    	
    	set("class","huashan");
    	set("combat_exp",400000);  
    	    	   	 	
    	set_skill("anxiang-steps",100);
    	set_skill("dodge",100);
    	set_skill("move",100);
    	set_skill("unarmed",100);
    	set_skill("zhaixin-claw",100);
    	set_skill("throwing",100);
    	set_skill("tanzhi-shentong",100);
    	set_skill("force",100);
    	set_skill("hanmei-force",100);
    	set_skill("perception",200);
    	
    	map_skill("force","hanmei-force");
    	map_skill("unarmed","zhaixin-claw");
    	map_skill("throwing","tanzhi-shentong");
    	map_skill("move","anxiang-steps");
    	map_skill("dodge","anxiang-steps");
    	
    	set("inquiry", ([
   	]));
    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({

        }) );  	
    		
	setup();
    	carry_object(__DIR__"obj/meihua_cloth")->wear();    
    	carry_object(__DIR__"obj/meihua_dart")->wield();
}

void 	init(){
        object ob;
        ::init();
        if( interactive(ob = this_player())) {
     		this_object()->kill_ob(ob);
        }
}


void	die(){
	object cloth;
	object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	} 
        
	message_vision(MAG"
÷��������ͻ�ֿ־壬���ζ��䣬˫�ּ��ӣ��������һ��Ѫ������÷���ϡ� 
һ��Ũ���Ѫ������������һ�����ܣ����μ��ˡ�
÷��������Ŀ���Ц�ţ�Ц�����Ѿ���Ӱ���١�"+HIR"

÷��ǧ�䣬���������� 


 
"HIC"Ѫ��ɢ��������ֻ��һ��׺��÷����ɴ��\n"NOR,this_object());

	cloth = new(__DIR__"obj/ty-meihua_ribbon");
	cloth->set("real",1);
	if (cloth) cloth ->move(environment(this_object()));
	
	if (me && REWARD_D->riddle_check(me,"�һ���̽��"))
		REWARD_D->riddle_set(me, "�һ���̽��",2);
	destruct(this_object());
}



void 	unconcious(){
	die();
}



int heal_up()
{
	if(environment() && !is_fighting() && !is_busy()) {
		message_vision("��Ӱ������÷��������Ӱ���١�������\n",this_object());
		destruct(this_object());
		return 1;
	}
	return ::heal_up() + 1;
}

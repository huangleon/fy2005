// drinkmonk.c
#include <ansi.h>
inherit NPC;

int go_in();
void create()
{
    	set_name("�������",({"drink monk","monk"}));
    	set("long","����һ��ɮ��ɮ�ײ��ף���ͷ�ҷ��Ĺ���\n");
    	set("gender","����");
    	set("no_arrest",1);
    	set("age",42);

    	set("combat_exp",1000000);
    
    	set_skill("force",100);
    	set_skill("lotusforce",100);
    	set_skill("unarmed",100);
    	set_skill("parry",150);
    	set_skill("dodge",150);
    	set_skill("dabei-strike",150);
    	set_skill("nodust-steps",120);
    	
    	map_skill("unarmed","dabei-strike");
    	map_skill("dodge","nodust-steps");
    	map_skill("force","lotusforce");
    
 	set_temp("apply/attack",150);
	set_temp("apply/dodge",100);
    
    	set("attitude", "heroism");
    	set("inquiry",([
        	  "meat": (: go_in :),
          	"��"  : (: go_in :) ,
          	"���丳" : "�˸����˳��̲����䣬����������֮�����������������ˡ�\n",
           ])   );
    	set("chat_chance",1);     
    	set("chat_msg",({
        	  "��������������������䶯Ҳ��������ޣ��׵繲�������侲Ҳ������𩾵���ǿ����䣡��\n",
          	"��������ƿ����ǿ���һ��\n",
          }) );

    	setup();
    	carry_object(__DIR__"obj/cloth_d")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int greeting(object me)
{
 
    if( !me || environment(me) != environment() ) return 1;
    say ("�������˵������������һ���ɡ�\n");
    return 1;
}


int go_in()
{
    object killer, *enemy;
    if ( is_fighting() ) {
    	enemy = query_enemy();
    	for ( int i =0; i<sizeof(enemy); i ) {
    		if (environment(enemy[i]) == environment(this_object())) {
    			killer = enemy [i];
    			break;
    		}
    	}
	message_vision(HIY"$Nһ�ߴ�һ�ߺ��������ڲ����⣬�����ҷŵ����" + RANK_D->query_rude(killer)
		+"�ٳ��⣡��\n"NOR,this_object());     	
    	return 1;
    }

    command("say �㲻˵�ҵ����ˣ������Ұ���������ȥ����˵����");
    message_vision("$N˫���������룬�ߵ�С���ſڡ�\n",this_object());
    command("cat");
    message_vision("$N���Ż������ƿ�һ�ߣ��������˽�ȥ��\n",this_object());
    this_player()->start_busy(1); 
    call_out("disap",1);
 
    return 1;
}

void disap()
{
	object room;
   	message_vision("��Ȼ���ڡ���ѽ��һ����������Ǻॡ�һ�����죬�Լ�������Ҳ���ڵ��ϡ�\n",this_object());
	room=find_object(AREA_TIEFLAG"maoroom1");
	if(!objectp(room))
	room = load_object(AREA_TIEFLAG"maoroom1");
	this_object()->move(room);
                call_out("greeting2", 2);
}


int greeting2()
{

    say ("�������˵���������˷��ӽ���ȥ�����Ӿ�Ҫ�Ǵ��ˡ������������ҲҪץ����������\n");
    say ("�������ˣ�����������ͨһ�����ƺ���ʲô����������ȥ��\n");
    destruct( this_object());
    return 1;
}


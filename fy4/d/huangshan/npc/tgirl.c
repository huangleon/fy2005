
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ɲ�Ů", ({"girl", "caicha girl"}) );
        set("gender", "Ů��" );
        set("age",16+random(4));
        set("long", "��ֵ����Ĳɲ�Ů��æµ��ժȡ�����ϵ���Ҷ��˫����Է۵�����
����ķ�������ɫ�Ĳ�����\n");
        set("attitude", "friendly");
        set("chat_chance", 1);
        set("no_arrest", 1);
        set("chat_msg", ({
		CYN"�ɲ�Ů�㽵�˵�������Ƴ����Ů���Ӵ��Ŀ���Ư��������Ľ�����ˡ���\n"NOR,
        }) );
	setup();

	carry_object(__DIR__"obj/ycloth")->wear();
	carry_object(__DIR__"obj/shoe1")->wear();
	carry_object(__DIR__"obj/tea");
}

int accept_object(object who, object ob){
	object me, tea;
    	string  id;
    	int i;
   
   		me=this_player();
    	if( ob->name() == HIR"��֬"NOR) {
	    	if(me->query("gender") == "����" && (me->query("age") < 26 && me->query("age") > 18)) {
	    		message_vision("$N��������" + ob->name() + "��һ����Ʒ���˫�ա�\n", 
	            	     this_object(), me);     
	    	}
	        message_vision("$N�����Ц��Ц˵��������л��λ" + RANK_D->query_respect(me) + "��\n",
	        		this_object(), me);        	    	            
	    	tea=present("tea",this_object());
	    	if (tea) {    	
	    		message_vision("$N˵������������²ɵĲ�Ҷ������Щȥ�����ʰɡ���\n",this_object());
	    		if (!tea->move(me))
	    			destruct(tea);
	    		return 1;
	    	}
    	}
}

void die()
{
	object tea;
	if(tea=present("tea",this_object()))
	{
		message_vision(RED"\n��Ѫ���˿��������ɲ�Ů����ã����ɫ�����㣬��������£����̵Ĳ�ҶȾ��\n"NOR,this_object());
		message_vision(RED"��Ѫ�ۣ��Ӳɲ�Ů�����л��䣬Ʈ���ڵ��ϡ�\n"NOR, this_object());
		tea->set("long", "Ⱦ����Ѫ�۵Ĳ�Ҷ��\n");
		tea->set("����",0);
		tea->set("value", 20);
		tea->move(environment(this_object()));
	}	
	::die();
}
// jademaker.c
#include <ansi.h>
int stone();
inherit NPC;

void create()
{
	set_name("�޴��", ({ "luo", "jade maker", "��" }) );
	set("gender", "����" );
	set("title", "��ʯ��");
	set("age", 55);
	set("long", "
����һ˫�������۾�����˫�ۿ��Էֱ���ʯ������������һ˫���֣�
����˫������԰���ʯ��������������\n");
	set("combat_exp", 50000);
	set("env/wimpy", 10);
	set("chat_chance", 1);
	set("chat_msg", ({
		"��������������ϴ�С�������ı��ݴ�ζ����������\n",
		"�����������������ɫ��ʯ����ɫ��ʯ���ѵ���ֻ��һ����˵�𣿡�\n",
	}) );
	set("inquiry", ([
        	"stone" :	(: stone :),
        	"��ɫ��ʯ" : 	(: stone :),
        	"���ݴ�":	"������ûʲô���ã��Ͱ���Щ�ò裬�����裬��ɽ�裬�����ǻ�ɽ������衣����\n",
        	"�Ŷ���":	"�Ŷ������Ŷ�����ԭ����Ӣ�����������Ǹ�������̽�������ˡ�\n",
    	]) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
}


void init(){
    	int i, left;
    	object me;
    
    	::init();
    	me = this_player();
    	i = me->query("marks/��¶��ʯ_Timeyantai");
		if (!i)	return;
      	remove_call_out("yantai");
      	call_out("yantai", 1, me);   
    
}


int stone(){
	object me;
	me = this_player();
	if(this_object()->is_fighting() || this_object()->is_busy()) {
		return 0;
	}
	message_vision(YEL"$N΢΢һЦ��������˵������������ı�ʯ���κ�������ܵõ����е�һ
�֣����ܴ��еõ�������������������������¶���Ҳֻ����˵�ģ����Ƴ���
��������������Ե��Ƕ�ȥ����һ�¡���\n"NOR, this_object());
	return 1; 	
}

void yantai(object me) {
    	object obj;
    	int i, left;
    	
    	if (!me || environment(me)!= environment(this_object()))	return;		
    	i = me->query("marks/��¶��ʯ_Timeyantai");
		if (!i)	return;
			
		left = i + 4320 - time(); // 72mins һ�Σ�һ���ڷܵ�at least ���� 10 ��, 10silver ��̨
				
    	if (left >0) {
    		tell_object(me,"��ʯ��̧ͷ����������˵���������ˣ�����Ҫ��"+ (left/60) +"���ӡ�\n");
    		return;
    	}
    	
    	//	L30 ���µ�dummy�ǣ��������ò����ġ� 1/10 �������һ����
    	if (!random(10) && F_LEVEL->get_level(me->query("combat_exp"))> 30) {
        	message_vision(YEL"
��ʯ��̾�˿�����$n˵���������ˣ���Ҳ�������ˣ���̨�����ˣ�
�����ҼҴ���̨�����͸���ɡ���\n"NOR,this_object(),me);
    		obj = new(__DIR__"obj/yantai2");
    		REWARD_D->riddle_set(me,"��¶��ʯ",4);	// ������˺�����ٻ���, reset here.
    	} else {
        	message_vision(YEL"��ʯ��˵��������λ" + RANK_D->query_respect(me) + "�����Ǽӹ��õ���̨��\n"NOR, 
                	this_object(), me);
        	if(me->query("marks/��¶��ʯ_Coloryantai") == "��") {
            		obj = new(__DIR__"obj/yantai");
        	} else if (me->query("marks/��¶��ʯ_Coloryantai") == "�Ϻ�") {
            		obj = new(__DIR__"obj/yantai1");
        	}
    	}
    	obj->move(me);   
    	me->delete("marks/��¶��ʯ_Coloryantai");
    	me->delete("marks/��¶��ʯ_Timeyantai");
    	REWARD_D->riddle_done(me,"�ӹ�ʯ��",10,1);	// �������ظ���
}



int accept_object(object me, object ob){
	object dog;
	string color;
	
	if (ob->query("name") == HIM"�Ͼ���ʯ"NOR && ob->query("jile")==1){
			
			if (REWARD_D->riddle_check(me,"�Ͼ�֮��")==2 
				|| REWARD_D->riddle_check(me,"�Ͼ�֮��/�޴��")) {
				command("shake");
				command("say �㻹�����Ҹ��˰ɡ�");
				return 0;
			}
			
			message_vision(CYN"$N����"+ob->query("name")+NOR+CYN"���˼��£����ó�����Ƭ����Ƭ�̣�üͷ������\n"NOR, this_object());
			ccommand("hmm");
			ccommand("say �Ϸ�������ʮ���꣬������û���������ֵ��Ͼ����㻹����Ѱ���˰ɡ�");
			REWARD_D->riddle_set(me, "�Ͼ�֮��/�޴��",1);
			
			if (sizeof(me->query("riddle/�Ͼ�֮��"))==4) {
				tell_object(me, CYN"\n"+name()+CYN"˵��ֻ��һ���˻�֪����鱦ʯ���������������ֽйŶ�����
��˵������������͸������ϵ��ڹ�Ĺ���ת����ڵ��׵�����ת�ı��
û������֪�������ģ���һ��֪���ⱦʯ�ĵ�ϸ��\n");
				REWARD_D->riddle_set(me,"�Ͼ�֮��",2);
			}
			return 0;
	}
					
	if(ob->query("����")){		// 2 types in fy2005 now...
		message_vision("$N���Ų�Ҷ�ŵ����ӵ��������ᣬ¶�������Ц�ݡ�\n", this_object(), me);
        message_vision("$N˵������л��λ" + RANK_D->query_respect(me) + 
",���಻�ţ�������ڼӹ���ʯ�������������໹��֪һ���� \n", this_object(), me);
    
        if (!REWARD_D->riddle_check(me,"�ӹ�ʯ��") && !REWARD_D->check_m_success(me,"��¶��ʯ"))
           	REWARD_D->riddle_set(me,"�ӹ�ʯ��",1);	// ��һ������Ҫ��ʯ��
	
	
	} else if( ob->query("��̨��") == 1 ){
	    	
	    	if (REWARD_D->check_m_success(me,"��¶��ʯ")) {	// not redoable
				message_vision("$N˵���Ҳ����Ѿ����洫����̨������ô��������ô��\n", this_object());
				return 0;
			}
	    	
	    	if (REWARD_D->riddle_check(me,"�ӹ�ʯ��")==2)
	    	{
	    		message_vision("$N˵��������������������Ͽ����ϻ�û�ӹ����ء���\n", this_object());
	    		return 0;
	    	}
	    		    	
	    	message_vision("$N������" + ob->name() + "ߵ�����£�Ц��:������ �����������һ���Ϻõ���̨����\n", this_object(), me);
        	if(REWARD_D->riddle_check(me,"�ӹ�ʯ��")==1) {
	            	message_vision("$N˵��������λ" + RANK_D->query_respect(me) + "�������ȡ��̨�ɡ���\n", this_object(), me);
	            	color = ob->query("color");
		        REWARD_D->riddle_set(me,"�ӹ�ʯ��",2);
		        me->set("marks/��¶��ʯ_Timeyantai", time());
		        me->set("marks/��¶��ʯ_Coloryantai", color);
	    	}else {
	        	message_vision("����˵�������������������θ�ڲ��ã����ٽӻ��ˡ���\n", this_object(), me);
	        	return 0;
	    	}
	} else if (ob->name()==YEL"������"NOR || ob->name()==GRN"��ɽ��"NOR) {
		message_vision("$N˵���������Ϻõ����裬���������ڵ���ʱ���ƺ����ˣ�������ඡ���\n",this_object());
		return 0;
	} else if (ob->name()=="�����") {
		message_vision(CYN"$N�޵�һ��˵�������Ǻò裬��ϧ����Ѫ��֮������\n"NOR,this_object());
		message_vision(CYN"$N���������ڣ���������һֻ���򹷡�\n"NOR,this_object());
		command("say ���ӣ����Ҹ�����ȥ��");
		if (!dog=present("shepherd dog",environment(this_object()))) {
			dog=new(__DIR__"sheepdog");
			dog->move(environment(this_object()));
		}
		dog->fight_ob(me);
		me->fight_ob(dog);
		return 0;	
	}else {
		message_vision("����ҡͷ˵�����Ҳ���Ҫ�������\n", me);
	    	return 0;
	}	
	return 1;
}


inherit SMART_NPC;

#include <ansi.h>
int ask_for();

void create()
{

        set_name("��ͣ", ({ "zhu ting","zhu" }) );
        set("gender", "����" );
        set("nickname",HIC"����"NOR);
        set("age", 42);
        set("long", "��ͣ�Ǹ��ܶ������ܵ��ˣ����Ҷ�ʲô�¶��ܿ��ÿ����ֵ��˿�
�����Ǻ��и��������ӣ��и������˲������ϰ塣\n");

        set("combat_exp", 3800000);
        set("chat_chance", 1);
        set("chat_msg", ({

        		"��ͣ�����ؿ�����һ�ۣ�����ͷ������̫ʦ���ϴ��ź��ࡣ\n",
		        "��ͣЦ��Ц��������Ҳ��������һ��Ư���������ʲôҲ�뿪�ˡ�\n",
		        "��ͣ�ճյ�����̫ʦ���ϣ���֪�ں�˼����ʲô��\n",
		}) );

        set("attitude", "friendly");

        set("inquiry", ([
           "��" : (: ask_for :), 
           "sword" : (: ask_for :),
        ]) );
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",170,160,0,"/obj/weapon/","fighter_w","nine-moon-claw",1);
        setup();
        carry_object("/d/fugui/npc/obj/m_cloth2")->wear();

}



int accept_fight(object me)
{

        command("say �������������㶼���Ź���������ڰ���\n");
        return 0;

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

void greeting(object me)
{
        object sword;
        
        if (!me 
        	|| environment(me) != environment())	
        	return;
        if(!me->query("sword_carrier")) {
        	
        	
        	
        	
        	return ;
        }
        if(me->query("sword_carrier")+1080>time())
		{
			ccommand("shake");
			ccommand("say ���˰����޽����һ��óԣ�����˯�����úϻ���������ޣ���������ô�죿");
			return;
		}
        if (!me->query("marks/zhu_8sword"))
        {
	  	message_vision( HIG "���շ·�ǧ�꣬����ȵý�ͷ�ö�ļ����֮�ʡ�������
          ��ͣ�������������˳�����˫������"HIC "���콣��" HIG "��С�������������С�
          \n\n��ͣ�������������ǧ�������ĥȥ�����콣��Ѫɷ֮����һ�ٸ�����������ȥҲ��������Ѵ���֮����
          ��ͣ̾�˿���������ȥ�ɣ��Լ�����Ϊ֮�� \n"NOR,me);
        	sword=new(__DIR__"obj/fixed_8sword");
        	sword->move(me); 
			me->set("marks/zhu_8sword",1);
        	me->delete("sword_carrier");
        }   
                                 
		return ;

}


int ask_for()
{
        object me;
        
        me=this_player();       
        if(me->query("marks/zhu_8sword")) 
        {
                message_vision("��ͣ���˸�������ƲƲ��������ϴ��㲻��������ô��С��Ӳ��Ӵ���ͷ�͡���\n",me);
                return 1;
        }
        if(me->query_temp("search_zhu_sword"))
        {
        message_vision(HIC "��ͣ����������˽�ȱһ���� ������\n"NOR,me);
                return 1;
        }

      message_vision(HIC 
"��ͣ��������Բ�����Ķ�����������Խ���˽�����һ��������ʯ��Ϊ�˿���죬��˵������λ�������
��ֻ����һ������֮����������ʱ���ʧɫ��Ѫ�����죬��Ϊ���飬�Ƿ�Ϊ�˽�����λ"+RANK_D->query_respect(me)+"
Ҫ����������콣�����輯��˽����ɣ�"NOR, me);
    message_vision(HIW "\n��ͣ΢΢��������˯�ۣ�ãȻ���˿��㣬�ּ���������˯��\n"NOR,me);
        me->set_temp("search_zhu_sword",1);
        return 1;
}

string *material_names=({
    "�ϵ�������", "�ϵ��Ķ�ˮ", "�ϵ���ת��", "�ϵ�������",
"�ϵ��ľ���","�ϵ������","�ϵ���ȴа","�ϵ������"        });

int accept_object(object me, object ob)
{
        string ob_name;
        int i,success,sword_ok;
        
        if(!me->query_temp("search_zhu_sword")) 
                return 0;
                
        ob_name=ob->query("name");
        success=1;
        sword_ok=0;
      	for(i=0;i<8;i++)
        {
                if(ob_name==material_names[i])
                {
                        if(me->query_temp("zhu/"+ob_name))
                        {
                                message_vision("��ͣ������������ô������ѣ��ѵ�����Ʒ����\n",me);
                                return 0;
                        } 
                           me->set_temp("zhu/"+ob_name,1);
                           message_vision("��ͣ˫��������ӹ��̬֮һɨ���⣬ׯ�ص�����л��λ��"+RANK_D->query_respect(me)+"��"+ob_name+"�ҵ���һ���������������ڻ���֮�У���\n",me);
                           sword_ok=1;
                           return 1;    
                }
                        success=success*me->query_temp("zhu/"+material_names[i]);
        }
       if (sword_ok = 1)
       { 
        if(!success) return 0;
        sword_ok = sword_ok + 1;
        command("spank "+me->query("id"));
        message_vision(HIC "��ͣ�����˫Ŀ�����Ź⣬�����޵����������������콣�������ֿ��ؼ������ˣ� \n"NOR,me);
        message_vision(YEL"��̧ͣͷ������һ�ۣ������պ�ȡ����\n"NOR,me);
        me->set("sword_carrier",time());
        me->delete("search_zhu_sword");
        call_out("make_sword",1080,me);
        } else {
               message_vision("��ͣŭ������ʲô���������ң���\n",me);
	       return 0;
        }
  return 0;
}



void make_sword(object me)
{
        object sword;

        if(!present(me,environment()))
                return ;                
        if (!me->query("marks/zhu_8sword"))
        {
          message_vision( HIG "���շ·�ǧ�꣬����ȵý�ͷ�ö�ļ����֮�ʡ�������
          ��ͣ�������������˳�����˫������"HIC "���콣��" HIG "��С�������������С�
          \n\n��ͣ�������������ǧ�������ĥȥ�����콣��Ѫɷ֮����һ�ٸ�����������ȥҲ��������Ѵ���֮����
          ��ͣ̾�˿���������ȥ�ɣ��Լ�����Ϊ֮�� \n"NOR,me);
        sword=new(__DIR__"obj/fixed_8sword");
        sword->move(me);   
        me->set("marks/zhu_8sword",1);   
        }               
        return ;
}





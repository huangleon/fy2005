//Created by justdoit at May 2001 
//All Rights Reserved ^_^

#include <ansi.h>
inherit NPC;  
void create()
{
    set_name("�Ϻ���", ({ "old fox","fox" }) );
	set("nickname", HIW "���׼׼��"NOR);
	set("gender", "����");
	set("no_arrest",1);
	set("age", 45);
    set("long","����һ��������˪����ˮ�֡�\n");
	set("NO_KILL","ɱ������ô����ȥ���Ƶ��أ�\n");
	set("combat_exp", 150000);
	set("attitude", "friendly");
    set_skill("move",50);
    set_skill("dodge",60);
    set_skill("unarmed",60);
	set("attitude", "friendly");
    set("chat_chance", 2);
	set("chat_msg", 
	   ({
"�Ϻ����૵����õط������Ǻõط�������\n ",
	    }) );
	set("inquiry",
	   ([
	     "���Ƶ�" : "�ݹ����ഫ�����Ƶ����ϱߺ����Ⱥ��֮�С�\n",
	     "baiyundao" : "�ݹ����ഫ�����Ƶ����ϱߺ����Ⱥ��֮�С�\n",
	     "�õط�" : "ֻҪ������ó����ģ��ǵط����У�������������������������������ת�͵��ˡ�\n",
	     "������" : "ֻҪ������ó����ģ��ǵط����У�������������������������������ת�͵��ˡ�\n",
	    ]) );	
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object who, object ob)
{
	object room;
	if ( !objectp(ob) ) return 0;
	if ( ob->query("name")=="�⴬����Լ" )
	   {
	     if ( who->query("name")== ob->query("employer") )
	        { int boattype;
	          boattype=ob->query("shiptype");
	          switch( boattype ) 
	           {
		     case 0:
                 message_vision("�Ϻ���Ц���ж�$N˵�����ã�����������\n", who);
                 tell_object(who, HIY "���Ϻ����к����У���һԾ����ˮ�ֻ�����Сľ���ϡ�\n\n"NOR ) ;
	             message_vision("�Ϻ����$N����ľ������$N������������λ�͹٣���ֻҪһֱ���ϻ��Ϳ��Ե����Ƶ��ˡ���\n", who);
	             message_vision("�Ϻ������뺣ˮ�У�������ľ�����뺣�У���$N���˻��֣�˵������һ·�϶ౣ�أ���\n\n", who);
	             room = load_object("/d/baiyun/raft");
	             break;
		
		     case 1:
             message_vision("�Ϻ����$N����һ�ҽ�ʵ���õ�С�۱ߣ�˵������λ"+RANK_D->query_respect(who)+
			       "���ϴ������Ҫȥ���Ƶ������ϻ���\n",who);
             tell_object(who, HIY "������������΢΢�ζ���С���ϡ�\n\n"NOR );
		     room = load_object("/d/baiyun/boat");
		     break;
 		
                     case 2:
//		     message_vision("�Ϻ����$N����һ�Ҹ�Φ����̡����õĴ󺣴��ߣ�˵������λ"+RANK_D->query_respect(who)+
//			       "���ϴ������Ҫȥ���Ƶ�������ˮ�������ϻ���\n",who);
		     message_vision("�Ϻ���������ͷ�׷�����Ц�����󺣴��Դ����ϴ��Ǹ�����üë��ү�����󣬾���Ҳû��������������\n",who);
				return 0;
//
//		     tell_object(who, HIY "��������󡢴�ҡ��ڵ����˴�.......\n"NOR );
//		     room = load_object("/d/baiyun/seaship");
		     break;
	           }
	          who->move(room);
	          return 1;
	        }
	     else if ( who->query("name")!= ob->query("employer") )
	           {
	             message_vision("�Ϻ���������$N�ļ�򣬽ƻ���Ц��������λ�͹٣���ɲ����������봬��ǩ������Լ�������޷�Ϊ�����񡣡�\n",who);
	             return 1;
	           }
	   }
	else if ( who->query("gender") == "����" )
	   {
	     message_vision("$N�ó������ϼ���֣���������$n�ļ磬Ц���еض���������
���ҿ��Խ��ܸ��õط����㣬�������˵������Ͳ������ˡ���\n\n",this_object(),who);
	     return 1;
	   }
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

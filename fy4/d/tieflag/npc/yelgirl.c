// yellow.c
#include <ansi.h>
inherit NPC;
void create()
{       
        object armor;
        set_name(YEL"������Ů"NOR, ({ "yellow girl","girl" }) );
        set("long", "������ɴ��˿��������˪����˿Ʈ�\n");
        set("age", 16);
        set("gender", "Ů��");
        set("attitude", "peaceful");
        set("combat_exp", 500000);  
	
	set_skill("dodge",100);
	set_skill("parry",100);
	set_skill("move",100);
	set_skill("ill-quan",70);
	set_skill("tie-steps",70);
	set_skill("unarmed",100);
	
	map_skill("dodge","tie-steps");
	map_skill("unarmed","ill-quan");
	
        set("inquiry",([
        	"����" : "�����������İ���Ī���ڿ�ȸɽׯ�Ŀ�ȸ���ˡ�\n",
        	"��ȸɽׯ" : "��ȸɽׯ��һ֧��ȸ���������£����֪���ǿ�ȸ���Ѿ���ʧ���𣿡�\n",
        	"��ȸ��" : "��ȸ����ʧ����ȸͼȴ������������֪����˭�˵�����...\n",
            "peacock" :"��ȸ����ʧ����ȸͼȴ������������֪����˭�˵�����...\n",
            "��ȸͼ"  :"������ܰѿ�ȸͼ�������Ҿ͸�����һ����ȸ�����\n",
              ]) );
        set("chat_chance", 1);
        set("chat_msg", ({
                "������Ů˵���������֪�������������İ�����ʲô����\n",
        }) );
        setup();
        armor=new(__DIR__"obj/corclot");
	armor->set_name(YEL"����"NOR,({"yellow cloth","cloth"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corclasp");
	armor->set_name(YEL"����"NOR,({"yellow bangle","bangle"}) );
	armor->move(this_object());
	armor->wear();	
	armor=new(__DIR__"obj/corgirt");
	armor->set_name(YEL"�ƴ�"NOR,({"yellow belt","belt"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corhat");
	armor->set_name(YEL"��ñ"NOR,({"yellow hat","hat"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corboot");
	armor->set_name(YEL"��Ь"NOR,({"yellow boot","boot"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corribb");
	armor->set_name(YEL"�ƽ�"NOR,({"yellow ribbon","ribbon"}) );
	armor->move(this_object());
	armor->wear();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
   mixed foo;
   object *inv;
   object dress; 
   int i; 
     if (random(victim->query("combat_exp"))<100000) 
        {  
           inv = all_inventory(victim);
           if (sizeof(inv)==0) return;
           for (i=0;i<sizeof(inv);i++){
             dress=inv[i];
             if ((string)dress->query("equipped")=="worn" ) break;
            }
           if ((string)dress->query("equipped")=="worn" )
           {
                dress->unequip();
              victim->set_temp("mark/striped",1);     
              return victim->name()+YEL "���ϵ�"+dress->name()+"��$N����������\n"NOR;
           } 
          };

            
           
        return;
}

int accept_object(object me, object obj)
{                                                                 
	object peacock;
    
    if( (string) obj->query("name") == "��ȸͼ" && obj->query("real"))
	{
		if (query_temp("making") || query_temp("maked"))
		{
			message_vision("$N̾�˿�����˵���������Ѿ�����������һ���ˡ���\n",this_object());
			return 0;
		}
		command("smile");
		message_vision("$N˵��������ȸ������������ʮ��Ƭ��Ҷ�Ӵ��ƶ��ɡ���\n",this_object());
		me->set_temp("peacock",1);
		set_temp("making",me);
		return 1;
	}
		
	if( (string) obj->query("name") == "����Ҷ��")
	{
		if(query_temp("making")!=me || !me->query_temp("peacock") || obj->query_amount()<49)
		{
			message_vision("$N˵������˾Ͷ�л��\n",this_object());
			return 1;
		}
 		if (me->query_temp("peacock")!=1)
		{
 			if(time()-(int) me->query_temp("peacock_time") < 300)
 				message_vision("$N������������˼һ�û�������أ���\n",this_object());
				
 			else
 			{
 				message_vision("$N˵���������˺��������������ˣ������ơ���\n",this_object());
 				message_vision("$N�ݸ�$nһ����Ͳ\n",this_object(),me);
 				set_temp("maked",1);
 				delete_temp("making");        
 				me->delete_temp("peacock");
 				me->delete_temp("peacock_time");
 				peacock=new(__DIR__"obj/peacock");
 				peacock->set_temp("unused",1);
 				peacock->move(me);
 			}
		}
 		
 		else 
 		{
 			message_vision("$N˵����������͸�����������š���\n",this_object());
 			me->set_temp("peacock",2);
 			me->set_temp("peacock_time",time());
 		}
 	}
 	else
 	{
	 	if(me->query_temp("peacock")==1 || query_temp("making")!=me || !me->query_temp("peacock") || (obj->value()<10000))
		{
			message_vision("$N˵������˾Ͷ�л��\n",this_object());
			return 1;
		}
 		if (me->query_temp("peacock")!=1 )
  			if(time()-(int) me->query_temp("peacock_time") < 300)
 				message_vision("$N������������˼һ�û�������أ���\n",this_object());
 			else
 			{
 				message_vision("$N˵���������˺��������������ˣ������ơ���\n",this_object());
 				message_vision("$N�ݸ�$nһ����Ͳ\n",this_object(),me);
 				set_temp("maked",1);
 				delete_temp("making");
 				me->delete_temp("peacock");
 				me->delete_temp("peacock_time");
 				peacock=new(__DIR__"obj/peacock");
 				peacock->set_temp("unused",1);
 				peacock->move(me);
 			}
 		
 		else
 	    	return 1;
 	  }
 	  return 1;
}
 	

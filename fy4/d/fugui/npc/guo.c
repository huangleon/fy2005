#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����·", ({ "guo", "guo dalu" }) );
        set("long", "����·���󷽵Ĵ���·��·����������������·�Ǹ��ܴ�·���ˡ�\n");
   		set("class","fugui");
        create_family("����ɽׯ", 7, "ׯ��");
        set("rank_nogen",1);
        set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		set("ranks",({ "С����","����","������","С����","����","������",
                "С����","������","��ʿ","����","ǹ��","ǹ��",CYN"ǹ��"NOR,
                CYN"ǹ��"NOR,CYN"����ǹ��"NOR,HIC"����Ӣ��"NOR}));
		set("attitude","friendly");
                   	
		set("chat_chance",1);
		set("chat_msg",	({
			"����·˵�������������ѵ����������������Ͳ������첻�����ģ�
�������������ϳԵ�ѼƤ�¶��Ѿ������ÿ����ˡ���\n",
			"����·˵���������뿪����ɽׯ��ô���ˣ�������ׯ������ֵ��ǣ�
��ׯ���������Ҷ�డ��\n",
			
		})  );
        
        set("combat_exp", 4000000);
        
        set_skill("move", 150);
        set_skill("foreknowledge", 100);
        set_skill("parry", 130);
        set_skill("dodge", 130);
        set_skill("spear", 150);
        set_skill("chanting", 100);
        set_skill("perception",100);
        set_skill("force", 150);
		set_skill("unarmed", 150);
		set_skill("literate", 100);
        
        set_skill("skyforce",140);
        set_skill("xuezhan-spear",150);
        set_skill("hawk-steps",150);
        set_skill("eagle-claw",150);
        
        map_skill("force", "skyforce");
		map_skill("parry","xuezhan-spear");
		map_skill("spear","xuezhan-spear");
        map_skill("dodge","hawk-steps");
        map_skill("move","hawk-steps"); 
        map_skill("unarmed","eagle-claw");  
	
		set("inquiry",	([
			"�þ�":  "���кþƣ�����������ң�\n",
			"����" : "�����ҹ���·�ĺ��ֵ�,������....�����Բ�ס��....\n",
			"��̫ƽ" : "�����ҹ���·�ĺ��ֵ�,������....�����Բ�ס��....\n",
			"����" : "�����ҹ���·�ĺ��ֵ�,������....�����Բ�ס��....\n",
			"ѼƤ" : "���Ϲ�������ͷ�ӵ���Ѽʵ�ڲ���ʵ�ڲ���\n",
			"��Ѽ" : "���Ϲ�������ͷ�ӵ���Ѽʵ�ڲ���ʵ�ڲ���\n",
			"wangdong" : "�����ҹ���·�ĺ��ֵ�,������....�����Բ�ס��....\n",
			"lintaiping" : "�����ҹ���·�ĺ��ֵ�,������....�����Բ�ס��....\n",
			"yanqin" : "�����ҹ���·�ĺ��ֵ�,������....�����Բ�ס��....\n",
			"kaoya" : "���Ϲ�������ͷ�ӵ���Ѽʵ�ڲ���ʵ�ڲ���\n",
			"��Ҷ��":	"��ɲ���Ѱ��С�������򵽵����֣��������ֵܶ���
�Ĳػ�����ϧ���߲ذ˲أ����Լ�����֪�����Ķ�ȥ�ˡ�\n",
			]));
		setup();
        carry_object("/obj/armor/cloth")->wear();
}


void attempt_apprentice(object ob)
{
        if( find_call_out("do_recruit") != -1 )
             command("say ������һ��һ������");
        else
             call_out("do_recruit", 2, ob);
       
}

void do_recruit(object me)
{
		
		
		if( me->query("gender") != "����" )       {
          	command("say ��ֻ���е��ӣ��㻹����ı�߾Ͱɣ�");
          	return 0;
          }
          
        if(!me->query_temp("marks/��Ѽ"))        {
        	command("say �Ҷ��ӿտ���Ҳ������ʲô��˼��ͽ�ܰ���");
        	return 0;
		  }
	  	
	  	if(!me->query_temp("marks/���߹�"))  	{
	  		command("say ��ɤ��ð������ʲô��˼��ͽ�ܰ���");
	  		return 0;
	  	}
	  	
	  	command("say �ֵ�������·�����������ȴ��ͷ���£��Ҿ�����Ϊͽ�ɣ�\n");
        command("recruit " + me->query("id") );
	  
}

void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "fugui");
}

int accept_object(object who, object ob)
{	
		object jinlian;
	
		if (ob->query("liquid/type")=="alcohol")
		{
			if (ob->query("liquid/remaining")< 50)
			{
				command("say ����Ц�ɣ��ÿյ���ƭ�ң�");
				return 0;
			}

			if (ob->query("name")=="���߹�") {
				write("����·�������߹޵���ǣ����Ƶ�����У��з����۾�������¶����
������顣���ã�����·����һ���������˼伫Ʒ���˼伫Ʒ������\n");
				who->set_temp("marks/���߹�",1);
				return 1;
			}

		if (ob->query("name")==HIG"��̳"NOR 
			&& ob->query("liquid/name")=="��Ҷ��") {
				
			if(ob->query("liquid/remaining")==1500 )
			{
				write("����·�����̳����ǣ������۾����������˿�����̾�������ⲻ��
��������ֱ������������\n");
				command("pat " + who->query("id"));
				write("����·��Ц�������ֵܱ��ҹ���·��Ҫ��·����\n");
				
				if (who->query_skill("hawk-steps",1)>120)
				{
					write("����·˵���������������鷳�㽻���Ҵ��������
˵����·�������뻹�ǻ�ɽׯ�ĺã������з����о�
�ȣ��������Ǽ��������ѣ��ٸ�������Ҳ�����ˡ�\n");
	        		jinlian = new(__DIR__"obj/chain");
	        		jinlian->move(who);
	        		who->set_temp("marks/�õ�����",1);
        		} else if (who->query("class")== "fugui")
        		{		
        			write("����·˵��������һ��ѧ����һ��Ҫ�����أ����ϵظ����������ĺþ�����");
        		}    			
        		return 1;
       		}
			else 
			{
				write("����·��ʱ���۷Ź⣬һ��������������ͷ�λ��Դ�˵�����ô��
������ӣ���ϧ̫�٣�����񫣬����񫣡\n");
			}
			return 1;
		}
				
		command("shake " + who->query("id"));
		command("say ��Ҳ�о�����ڲ�����������ζ������񫣬����񫣬��Ҫ����"YEL"�þƣ�\n"NOR);
		return 0;
				
		}
	
		if (ob->query("name")=="��Ѽ")
		{ 
			who->set_temp("marks/��Ѽ",1);
			write("����·һ�´���������е������������Ϲ����Ѽ������������·����\n");
			return 1;
		}
	
		message_vision("$Nɨ��һ��$n���еĶ�����������˵���������ֶ�����������������ˡ���\n",this_object(),this_player());
		return 0;
}


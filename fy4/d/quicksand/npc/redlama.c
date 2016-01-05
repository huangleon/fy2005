// Silencer @ FY4 workgroup. Aug.2004

inherit NPC;
void create()
{
	set_name("����", ({ "chi song", "song" }) );
	set("title", "��������");
	set("gender", "����" );
	set("class","lama");
	set("age", 52);
	set("skill_public",1);
	set("int", 30);
        create_family("������", 21, "����");
	
	set("long",
		"���ɱ��Ǹ��׸�ɮ�ĵ������ӣ����Ǳ����ݺ���������Ϊ��͵\n"
		"�������ӣ��������ʦ�ţ����ڴ˹ȣ���������˫�㣬����˵��\n"
		"�����ӵ����䡣��˵�������ӵ����䣬�����ɻز���������\n"
		);
       	
       	set("chat_chance", 1);
        set("chat_msg", ({
                "����˵����˭�����һ������ӣ��Ҵ����������񹦣�\n",
                "����˵�������ɡ�����Ϊ���������ŵ���֮λ����Ȼ�ݺ����ң�\n"
        }) );

	set("inquiry", ([
		"������": "��....������һ������ʦ�����ɵ��ߵġ�\n",
		"����": "�����ڲ��������ǵĴ������",
	]) );
	
	set("attitude", "peaceful");
	
	set_skill("iron-cloth", 150);
	
	set_skill("unarmed", 150);
	set_skill("bloodystrike", 120);
	set_skill("force", 150);
	set_skill("bolomiduo", 100);
	set_skill("dodge",120);
	set_skill("parry",120);
	
	map_skill("unarmed", "bloodystrike");
	map_skill("force", "bolomiduo");
	map_skill("parry", "bloodystrike");
	
	set("combat_exp", 1200000);
	setup();
}

int recognize_apprentice(object ob)
{
        if( !ob->query("free_learn/iron-cloth") ){
                say("����˵������ֻ�а��һز����������ҲŻ����....\n");           
                return 0;
        }

        return 1;
}

int accept_object(object who, object ob)
{
	int bonus;
	if( ob->name() != "������" && ob->name() != "�߻�����")
	{
	        say("����˵����������Ҫ����������....\n");
			return 0;
	}
	
	
	if (ob->name() == "������"&& ob->query("nature")!= "real" )
       {
    		say("����˵����������Ҳ������ƭ�ˣ����������Ǽٵ�....\n");
            return 0;
        }
        
	if (ob->name()== "�߻�����")
	{
		if (!REWARD_D->riddle_check( who,"��������")) 
			return 0;
		else {
			say("���ɴ�ϲ���ã���С��Ҳ�н��죡\n");
			say("����˵����λ"+ RANK_D->query_respect(who)+"��лл��������������Ϣ����\n");
			who->set("free_learn/iron-cloth",1);
		    REWARD_D->riddle_done(who, "��������",50,1);
		    return 1;
			}
     }	else
	 {
			who->set("free_learn/iron-cloth", 1);
			say("����˵�����ã��ã��ã�̫���ˣ��ҵ�ԩ���ڼ�������....\n");
        	REWARD_D->riddle_done(who, "��������",50,2);
			return 1;	
	 }
		return 1;
}


int prevent_learn(object me, string skill)
{
  	if (skill != "iron-cloth")
  	{
      		command("shake");
      		command("say �ҿ�ֻ��Ӧ��������������");
      		return 1;
  	}
  	return 0;
}


int prevent_shown(object me, string skill)
{
	if (me->query("free_learn/iron-cloth")	&& skill == "iron-cloth")
		return 0;
	
	return 1;
}
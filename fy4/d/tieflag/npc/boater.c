// boater.c

inherit NPC;

void create()
{
    	set_name("������",({"old boater","boater"}));
    	set("long","
�����ݱ�������ʴ�����괵�򣬻�����ǧ�������ƣ��Ե���ô˥��
��һ˫�۾���ȴ���������磬����ֻҪһ���ƹ�ȥ���κ��˵����ܣ�
ȴ��Ҳ������������\n");
    
    	set("gender","Ů��");
    	set("age",62);
    	set("no_arrest",1);
    	set("combat_exp",111110);  
      	set("NO_KILL","ɱ�������谭��ͨ�ġ�\n");
    	set("attitude", "friendly");
		set("chat_chance",2);
		set("chat_msg",({
			"��������ѽ��ѽҡ���֡�\n",
    	}) );
    	setup();
    	carry_object("/obj/armor/cloth")->wear(); 
    	carry_object(__DIR__"obj/changgao")->wield();
    	
}

void unconcious()
{
::die();
}

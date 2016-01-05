// dtz.c

inherit NPC;
int random_action();
void create()
{
        set_name("��ū", ({ "gui nu","nu" }) );
        set("gender", "����" );
        set("age", random(25)+15);
        set("long", "һ��Ϊǧ��¥Ч�������ڿ��ŵĹ�ū\n");
	set("per",30);
        set("combat_exp", 100000);
	set("no_arrest",1);
        set("attitude", "heroism");
        set_skill("unarmed", 200);
        set_skill("parry", 200);
	set_skill("dodge", 200);
        set("chat_chance", 2);
        set("chat_msg", ({
                (: random_action :)
        }) );
        set("inquiry", ([
                "���ϰ˽�" : "Ŷ�����Ƕ�ס�ںɻ����ϣ�\n",
                "������" : "��θ�ڿɴ��أ�û�������Ӷ����뿴����Ц��\n",
                "liu" : "��θ�ڿɴ��أ�û�������Ӷ����뿴����Ц��\n",
        ]) );


	setup();
	carry_object("/obj/armor/cloth")->wear();
        
}


int accept_object(object me, object obj)
{
    command("smile");
	if (obj->query("value") >= 2000)
	{
        command("say ��л��λ" + RANK_D->query_respect(me) +
"����һ���ᣮ��������");
	me->set_temp("annie/pay_guinu",1);
	}
    return 1;
}


int random_action()
{
	int permit;
	permit=(int) environment(this_object())->query("enter_permission");
	if(!permit)
	switch(random(5)){
		case 0:
			command("zzz");
			break;
		case 1:
			command("yawn");
			break;
		case 2:
			command("bored");
			break;
			}
		else
	switch(random(5)){
	        case 0:
	message_vision("$N�����죬��������ǧ��¥�Ĺ��ȫ�����ģ�\n",this_object());
	                break;
	        case 1:
	message_vision("$N�������㼸�ۣ���Ǯ���Ǵ�ү��������ǧ��¥�ż䣡\n",this_object());
	                break;
	                }

}

void die(){
	object *inv, ob;
	int i;
	message_vision("$N�ҽ�һ��������ȥ��¥��ɿ���ܳ��߰˸�����̧����$N��ʬ��\n",this_object());	
	inv = all_inventory(this_object());
	for(i=0;i<sizeof(inv);i++){
		ob = inv[i];
		if(ob->query("name") != "����") {
			message_vision("��$N���ϵ�����һЩ������\n", this_object());
			ob->move(environment(this_object()));
		}
	}
	destruct(this_object());	
}
// yinbin.c
inherit NPC;
void create()
{
    set_name("����",({"yin bin","yin","bin"}));
    set("long","���������������ɴ����Լ��¶�������������������þ��ˣ�������
����ҩ�����￴����\n");
    set("gender","Ů��");
    set("age",42);
    set("per",35);
    set("combat_exp",50000);

    set_skill("nine-moon-force",20);
    set_skill("unarmed",100);
    set_skill("nine-moon-claw",40);
    set_skill("nine-moon-steps",40);
    set_skill("parry",50);
    set_skill("dodge",50);

    map_skill("force","nine-moon-force");
    map_skill("unarmed","nine-moon-claw");
    map_skill("dodge","nine-moon-steps");
    set("attitude", "friendly");
    set("chat_chance",5);     
    set("chat_msg",({
          "����Ц���������Ҫ���ƿ���ɴ���㿴��ô����\n",
          }) );

    setup();
    carry_object(AREA_TIEFLAG"npc/obj/redcloth")->wear();
    carry_object(AREA_TIEFLAG"npc/obj/redjin")->wear();
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
 
    command("lovelook");
    message_vision("�����۲���ת��Ц��������ֻ�����Եص����ˣ�����ƫƫ�����������\n",this_object());
    
    if( !me || environment(me) != environment() ) {
    	command("say ��Ҳ�����ˣ��������˽����أ�");
	    message_vision("$N����һЦ�����˳�ȥ��\n",this_object());
	    destruct(this_object());
    	return 1; 
    }
    call_out("leave",30,me);
    return 1;
} 

void leave(object me)
{
    if (is_fighting()) {
    	call_out("leave",30,me);
    	return;
    }  	
    command("say ��Ҳ�����ˣ��������˽����أ�");
	message_vision("$N����һЦ�����˳�ȥ��\n",this_object());      
    
    if (me && environment(me) == environment())
	      me->set_temp("mark/����",1);
    destruct(this_object());
}

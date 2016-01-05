inherit NPC;

void create()
{
        set_name("������", ({ "fighter", "taoist fighter" }) );
        set("nickname", "��ָС����");
        set("gender", "����");
        set("age", 20);
        set("long","�����������ָС���ˣ���˵�Ƕ��˷���ϲ����ͽ�ܣ�����ʦ���洫��
�ɲ�֪��Ϊʲô���ɵ������������š�\n");
        set("combat_exp", 100000);
        set("score", 500);
        set("class", "taoist"); 
        set("possessed",1);
	
        set("inquiry", ([
                "�����ķ�": 
"�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
        ]) );
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "invocation" :),
        }) );

        create_family("���幬", 6, "����");
        
        set_skill("magic", 50);
        set_skill("move", 50);
        set_skill("force", 50);
        set_skill("spells", 90);
        set_skill("unarmed", 50);
        set_skill("parry", 60);
        set_skill("dodge", 80);
        set_skill("gouyee", 90);
        set_skill("taoism", 80);
        set_skill("necromancy", 80);    
	set_skill("tenderzhi",50);
	set_skill("notracesnow",120);
	
	map_skill("dodge","notracesnow");
	map_skill("unarmed","tenderzhi");
        map_skill("force", "gouyee");
        map_skill("spells", "necromancy");

        set_temp("apply/dodge", 20);
        set_temp("apply/armor", 20);

        setup();
        carry_object("/obj/armor/cloth")->wear();

}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="���幬" ) {
                command("nod");
                command("say ���аɡ�");
                return 1;
        }
        command("say ���幬���ͱ��ɵ��˹��С�");
        return 0;
}
 

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/


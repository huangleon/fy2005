inherit NPC;
int kill_him();

void create()
{
        object armor;
        set_name("����ѷ", ({ "guo changxun" }) );
        set("gender", "����");
        set("age", 39);
        set("long","�䵱�����ŵ��ӣ���һ�����ɫ�ĵ��ۡ�\n");
        
        set("inquiry", ([
            "��­��" : (: kill_him :),
        ]));
        
        set("attitude","friendly");
        set("combat_exp", 4500000);
        set("score", 200);
        set("class", "wudang");
       
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({

        }) );
        
        set("no_busy",8);
        
        create_family("�䵱��", 58, "����");

        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("taijiforce", 200);
        set_skill("taiji", 180);
        set_skill("taiji-sword", 180);
        set_skill("five-steps", 200);
        set_skill("taiji",180);

        map_skill("force", "taijiforce");
        map_skill("sword", "taiji-sword");
        map_skill("parry", "taiji");
        map_skill("unarmed", "taiji");
        map_skill("dodge", "five-steps");
        map_skill("move", "five-steps");
        
        setup();

        carry_object(__DIR__"obj/sword")->wield();
//        carry_object(__DIR__"obj/skinmask2");
        armor=new("/obj/armor/cloth");
        armor->set_name("����ɫ�ĵ���",({"cloth"}) );
        armor->move(this_object());
        armor->wear();

}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="�䵱��" ) {
                command("nod");
                command("say ���аɡ�");
                return 1;
        }
        command("say �䵱�ɲ��ͱ��ɵ��˹��С�");
        return 0;
}

int kill_him()
{
        object me;
        me = this_player();

        if (REWARD_D->riddle_check(me,"�ž�����") != 4
        	&& REWARD_D->riddle_check(me,"�ž�����") != 5)
        {
                command("pure");
                command("dunno");
                return 1;
        }       

        command("emote ��ɫһ�������Ȼ��֪���ˣ�����������ȥ�ɣ�\n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        this_object()->set("have_mask",1);        
        REWARD_D->riddle_set(me,"�ž�����",5);
        return 1;
}
 
void die(){
        object *inv, ob, killer, owner;
        int i;
        
        if(objectp(killer=query_temp("last_damage_from") ))
        {
        	if ( objectp(owner = killer->query("possessed")))
    		killer = owner;
        
        	if (this_object()->query("have_mask") 
        		&& REWARD_D->riddle_check(killer,"�ž�����") == 5) {
                REWARD_D->riddle_set(killer,"�ž�����",6);
                ::die();
                return;
        	}
        }
        
/*      inv = all_inventory(this_object());
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if(ob->query("name")== "�����ŵ��·�") {
                        destruct(ob);
                }
        }*/
        ::die();
}


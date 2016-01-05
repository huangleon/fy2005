inherit NPC;

void create()
{
        set_name("���ӵĵ�ʿ", ({ "taoist" }) );
        set("gender", "����");
        set("long",
		"�䵱�ɴ��ӵĵ��ӣ���һ���ɫ�ĵ��ۡ�\n"
	);
        set("combat_exp", 70000);
        set("score", 200);
        set("class", "wudang");

        set_skill("move", 50);
        set_skill("force", 50);
        set_skill("unarmed", 50);
        set_skill("staff", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("taijiforce", 50);
        set_skill("taiji", 40);
        set_skill("five-steps", 40);
        set_skill("cloudstaff",50);

        map_skill("force", "taijiforce");
        map_skill("staff","cloud-staff");
        map_skill("parry", "cloud-staff");
        map_skill("unarmed", "taiji");
        map_skill("dodge", "five-steps");
        map_skill("move", "five-steps");
        
        setup();

        carry_object("/obj/weapon/staff")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
        

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
 

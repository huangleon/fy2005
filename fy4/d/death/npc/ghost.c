// ghost.c

inherit NPC;

void create()
{
        set_name("�»�Ұ��", ({ "wandering ghost", "ghost" }) );        
        set("age", random(65));
        set("str", 24);
        set("cor", 26);

        set_temp("apply/attack", 10);
        set_temp("apply/armor", 10);
        
        
		
		set("inquiry", ([
          	"���̲�" : 	"action�»�Ұ��ߴߴ����һ���ҽУ���ϧ��ʲôҲ��������\n",
      	]) );
        
        setup();
        carry_object("/obj/armor/ghost_cloth")->wear();
}

int is_ghost() { return 1; }




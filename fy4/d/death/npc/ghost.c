// ghost.c

inherit NPC;

void create()
{
        set_name("¹Â»êÒ°¹í", ({ "wandering ghost", "ghost" }) );        
        set("age", random(65));
        set("str", 24);
        set("cor", 26);

        set_temp("apply/attack", 10);
        set_temp("apply/armor", 10);
        
        
		
		set("inquiry", ([
          	"Ã÷ÑÌ²İ" : 	"action¹Â»êÒ°¹íß´ß´ÔûÔûÒ»ÕóÂÒ½Ğ£¬¿ÉÏ§ÄãÊ²Ã´Ò²Ìı²»¶®¡£\n",
      	]) );
        
        setup();
        carry_object("/obj/armor/ghost_cloth")->wear();
}

int is_ghost() { return 1; }




#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
		object weapon;
        set_name("¶«å­ÀËÈË", ({ "soldier" }) );
        set("attitude", "heroism");
        setup();

        weapon=carry_object("/obj/weapon/blade/pxblade");
        weapon->set_name("ÙÁµ¶", ({ "no-dachi" }) );
		weapon->set("long"," ");
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wield();

}



void die(){
	destruct(this_object());
}
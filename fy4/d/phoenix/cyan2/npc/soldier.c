#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
        set_name("Ã÷Ï¼ÊØ±¸", ({ "fengyun garrison", "garrison" }) );
        set("long","
ÕâÊÇ¸öÕýÔÚÖ´ÐÐÊØ³ÇÈÎÎñµÄÖµÇÚ±ø£¬ËäÈ»ºÍÐí¶àÎäÁÖÈËÎï±ÈÆðÀ´£¬ÕâÐ©Ð¡±ø
µÄÎä¹¦ÊµÔÚÆ½³££¬µ«ËûÃÇÊÇÓÐ×éÖ¯¡¢ÓÐ¼ÍÂÉµÄÕ½Ê¿£¬Ë­Ò²²»ÇáÒ×µØÕÐÈÇËûÃÇ¡£\n"
"[31mÄã×îºÃÒ²²»ÒªÕÐÈÇËûÃÇ¡£ [32m\n");
        set("attitude", "heroism");
	set("no_heal",1);

	set("chat_chance", 1);
	set("chat_msg", ({
		CYN"Ã÷Ï¼ÊØ±¸ËµµÀ£º½ñÌì¾ÍÊÇ°ÑÃüÔáÔÚÕâÀï£¬Ò²¾ø²»ÈÃÄÇÐ©Îå¶ÌÙÁÔôÕ¼È¥ÖÐÔ­Ò»²½ÍÁµØ£¡\n"NOR,
	}) );

        setup();

        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/longdagger")->wield();
}



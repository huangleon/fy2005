#include <ansi.h>

int rmhirdir(string dir);

int main(object me, string arg)
{
    	if( me->is_busy() )
        	return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»Íê³É¡£\n");

    	if( !arg )
    	{
        	write("ÄãÏë×ÔÉ±£¬µ«ÊÇÏëÁËÏëÓÖÏÂ²»ÁËÊÖ¡£\n");
        	return 1;
    	}

    	if( arg!="-f" ) 
        	return notify_fail("×ÔÉ±ÓĞÁ½ÖÖ£¬ÄúÊÇÒªÓÀÔ¶ËÀµô»¹ÊÇÖØĞÂÍ¶Ì¥£¿\n");

//		if (wizardp(me))
//		return notify_fail("¹ÜÀíÈËÔ±²»ÔÊĞí×ÔÉ±¡£\n");
		
		if (me->query("combat_exp")< 4000)
			return notify_fail("ÄãµÄ¾­ÑéÖµÌ«µÍ£¬ÏµÍ³²»×÷±£Áô£¬ÎŞĞè×ÔÉ±£¬ÍË³ö±ãÊÇ¡£\n");
		
    if (me->query("combat_exp")>= 2100000)
    	return notify_fail("
ÄãÔÚ·çÔÆÀïĞ¡ÓĞÃûÆø£¬ÒÑ¾­Ã»·¨ÇáÒ××ÔÉ±ÁË¡££¨µÈ¼¶¸ßÓÚ50£©
·çÔÆ½«ÔÚ²»¾ÃµÄ½«À´ÍÆ³öÍËÒşÏµÍ³£¬ÈÃÄã½ğÅèÏ´ÊÖ£¬ÓÀ±ğ½­ºş£¬ÎªºóÈËÁôÏÂÄÑÍüµÄ»ØÒä¡£\n");
    	
    write(HIR"Èç¹ûÄúÑ¡ÔñÓÀÔ¶ËÀµôµÄ×ÔÉ±·½Ê½£¬ÄúµÄ×ÊÁÏ¾ÍÓÀÔ¶É¾³ıÁË£¬Ò»µ©\n"
         	 "ÊäÈëÃÜÂëÔò²»¿ÉÔÙºó»ÚÁË£º\n"NOR);
		if (me->query("marry"))
			write(HIY"×¢Òâ£¡ÄãµÄ°éÂÂ½«Òò´Ë¶øÊØ¹Ñ£¬·çÔÆ¹¤×÷×éÒà²»»á¶Ô´Ë×÷\n³öÈÎºÎ²¹³¥£¬ÇëÉ÷ÖØ¾ö¶¨£¡\n"NOR);
   	input_to("check_password", 1, me, 1);
    return 1;
}

private void check_password(string passwd, object me, int forever)
{
    	object link_ob;
    	string old_pass;
    	string name;
    	link_ob = me->query_temp("link_ob");
    	old_pass = link_ob->query("password");
    	if( crypt(passwd, old_pass)!=old_pass )
    	{
        	write("ÃÜÂë´íÎó£¡\n");
        	return;
    	}

    	if (forever)
    	{
        	tell_object( me,WHT "
        	
        	Çï·çÇå£¬Çï·çÃ÷£¬
             ÂäÒ¶¾Û»¹É¢£¬º®Ñ»ÆÜ¸´¾ª¡£
        ÏàË¼Ïà¼ûÖªºÎÈÕ£¬´ËÊ±´ËÒ¹ÄÑÎªÇé¡£
        	
    ÓÀ±ğÁË£¬Ï£Íû·çÔÆÄÜ¸øÄãÁôÏÂÒ»¶ÎÄÑÍüµÄ»ØÒä¡£\n\n\n" NOR);
        	link_ob = me->query_temp("link_ob");
        	if( !link_ob ) return 0;

        	log_file("static/SUICIDE",
                	sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );

        	seteuid(getuid());

//      name = me->query("id"); CALL-ID Bug£¬ÈÃÎÒÃÇ´Ólink_ob»ñµÃÕâ¸ö²ÎÊı¡£
		name = link_ob->query("id");

        	if (me->query("combat_exp")>= 3000) 
        	{
        		LOGIN_D->cphirdir(DATA_DIR + "login/" + name[0..0] + "/" + name, "/suicide/login/"+name+time());
	        	LOGIN_D->cphirdir(DATA_DIR + "user/" + name[0..0] + "/" + name, "/suicide/user/"+name+time());
        	}
        	rmhirdir(DATA_DIR + "login/" + name[0..0] + "/" + name );
        	rmhirdir(DATA_DIR + "user/" + name[0..0] + "/" + name );

        	tell_room(environment(me), me->name() +
                  	"×ÔÉ±ÁË£¬ÒÔºóÄãÔÙÒ²¿´²»µ½Õâ¸öÈËÁË¡£\n", ({me}));
        	CHANNEL_D->do_sys_channel("info",me->name(1)+"("+me->query("id")+
                                  ")×ÔÉ±ÁË£¬ÒÔºóÄãÔÙÒ²¿´²»µ½Õâ¸öÈËÁË¡£");
        	destruct(me);
        	return 0;
    	}
}

int rmhirdir(string dirstr)
{
	string *dir;
	int i;
	dir = get_dir(dirstr+"/");
        for(i=0; i<sizeof(dir); i++) {
                if(file_size(dirstr+"/"+dir[i]) == -2 ) {
                                rmhirdir( dirstr +"/"+dir[i]);
                                rmdir(dirstr+"/"+dir[i]);
                                                }
                rm(dirstr+"/"+dir[i]);
        }
	rmdir(dirstr);
	return 1;
}

int help (object me)
{
        write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	suicide -f[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
 
Èç¹ûÒòÎªÄ³ÖÖÔ­ÒòÄã²»Ïë»îÁË, Äã¿ÉÒÔÑ¡Ôñ×ÔÉ±¡£
×ÔÉ±µÄ·½Ê½Îª:
 
suicide -f : ÓÀÔ¶µÄ³ıÈ¥Íæ¼Ò×ÊÁÏ, ÏµÍ³»áÒªÇóÄã
             ÊäÈëÃÜÂëÒÔÈ·ÈÏÉí·İ¡£
 
Èç¹ûÄãÒÑ½á»é£¬´ËÖ¸Áî½«µ¼ÖÂÄãµÄ°éÂÂÀëÒì¡£
ÇëÉ÷ÖØÑ¡Ôñ :)

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
 
HELP
);
        return 1;
}


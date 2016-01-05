// wizlock.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int lvl;

	if( me!=this_player(1) ) return 0;
	if( wiz_level(me) < wiz_level("(arch)") )
		return notify_fail("ÄãµÄÎ×Ê¦µÈ¼¶Ì«µÍ£¬Ã»ÓĞÊ¹ÓÃÕâ¸öÖ¸ÁîµÄÈ¨Á¦¡£\n");
	
	if( !arg || arg=="" ) {
		return notify_fail("µ±Ç°·çÔÆ¿ÉµÇÂ½µÄ×î´óÈËÊıÎª£º"+ LOGIN_D->query_max_users()+" \n");	
	}
	
	if( sscanf(arg, "%d", lvl)!=1 ) 
		return notify_fail("²Î¼ûHELP¸ñÊ½ËµÃ÷¡£\n");
		
	seteuid(getuid());
	
	if (lvl>0 && lvl<10) {
		LOGIN_D->set_dummy_number(lvl-1);
		write(sprintf("\nµ±Ç°Ã¿¸öip¿ÉÒÔÁ¬ÏßÈËÊıÉèÖÃÎª%d\n", lvl));
		return 1;
	}
		
	if( LOGIN_D->set_max_users(lvl)) {
		write(sprintf("\n½øÈëÓÎÏ·ÈËÊıÉèÖÃÎª%d	\n",lvl));
		return 1;
	} else
		return notify_fail("ÉÏÏßÈËÊıÉè¶¨Ê§°Ü¡£\n");
}

int help (object me)
{
        write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÎ×Ê¦Ö¸Áî¸ñÊ½ : 	loginlock <Êı×Ö>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

´ËÃüÁîÓĞÁ½¸ö×÷ÓÃ

£¨1£©µ±Êı×Ö<10Ê±£¬¿ÉÉè¶¨µ±Ç°ÓÎÏ·ÖĞÃ¿¸öip¿ÉÒÔµÇÂ½µÄÈËÊı£¨ÓÎÏ·Ä¬ÈÏÎª3£©

loginlock 1	ÒâË¼¾ÍÊÇÃ¿¸öipÖ»ÄÜÎªÒ»¸öÈË

£¨2£©ÏŞÖÆ¹²ÓĞ¶àÉÙÊ¹ÓÃÕß¿ÉÒÔ½øÈëÓÎÏ·¡£
Ã¿´ÎÖØÆô£¨»òÖØÔØlogind£©ºóÈ±Ê¡µÇÂ½ÈËÊıÎª£²£°£°£¬´ËÖ¸Áî¿É¶¯Ì¬ÉèÖÃ

loginlock 300		ÔÊĞíÍ¬Ê±µÇÂ½ÈËÊıÎª300

×¢£ºÈç¹ûÄãÒª¸øÄ³¸öip¶àÒ»Ğ©µÇÂ½ÈËÊıµÄ»°£¬Ê¹ÓÃnetbarÃüÁî

Ä¿Ç°netbarÄÜ×öµÄÊÇ
£¨1£©Õû¸öÓÎÏ·È¡Ïûip-idÏŞÖÆ
£¨2£©¸øÄ³¸öip¼Ó±¶loginÈËÊı

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m  
HELP
);
        return 1;
}
 

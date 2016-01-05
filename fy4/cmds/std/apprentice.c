// apprentice.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	object ob, old_app;
    	mapping family, skills;
    	int i, score_cost;
    	string *skname;

    	if( !arg ) return notify_fail("Ö¸Áî¸ñÊ½£ºapprentice [cancel]|<¶ÔÏó>\n");

    	if( arg=="cancel" ) {
        	old_app = me->query_temp("pending/apprentice");
        	if( !objectp(old_app) )
            	return notify_fail("ÄãÏÖÔÚ²¢Ã»ÓĞ°İÈÎºÎÈËÎªÊ¦µÄÒâË¼¡£\n");
        	write("Äã¸Ä±äÖ÷Òâ²»Ïë°İ" + old_app->name() + "ÎªÊ¦ÁË¡£\n");
        	tell_object(old_app, me->name() + "¸Ä±äÖ÷Òâ²»Ïë°İÄãÎªÊ¦ÁË¡£\n");
        	me->delete_temp("pending/apprentice");
        	return 1;
    	}

    	if( !(ob = present(arg, environment(me)))
        	|| !ob->is_character() )
        	return notify_fail("ÄãÏë°İË­ÎªÊ¦£¿\n");

    	if( mapp(me->query("family")))
        if(me->query("family/privs")==1)
            	return notify_fail("ÄãÔø¾­ÊÇÒ»°ïÖ®Ö÷£¬²»ÄÜÔÙ°İ±ğÈËÎªÊ¦ÁË¡£\n");
        else if(me->query("family/privs")==-1)
            	return notify_fail("ÄãÊÇÒ»°ïÖ®Ö÷£¬²»ÄÜÔÙ°İ±ğÈËÎªÊ¦ÁË¡£\n");
    
    	if(!ob->visible(me))
    		return notify_fail("¶Ô·½¿´²»¼ûÄã£¬ÔõÃ´°İÊ¦°¡£¿\n");
    		
    	if( !living(ob) )
        	return notify_fail("Äã±ØĞëÏÈ°Ñ" + ob->name() + "ÅªĞÑ¡£\n");

    	if( ob==me ) return notify_fail("°İ×Ô¼ºÎªÊ¦£¿ºÃÖ÷Òâ....²»¹ıÃ»ÓĞÓÃ¡£\n");

    	if( me->is_apprentice_of(ob) ) {
        	message_vision("$N¹§¹§¾´¾´µØÏò$n¿ÄÍ·Çë°²£¬½ĞµÀ£º¡¸Ê¦¸¸£¡¡¹\n", me, ob);
        	ob->re_rank(me);
        	return 1;
    	}

    	if( !mapp( ob->query("family") ) )
        	return notify_fail(ob->name() + "ÎŞÒâÊÕÍ½£¬ÄãÎŞ·¨°İËûÎªÊ¦¡£\n");
    
    	if( userp(ob) && (int) ob->query("family/privs") != -1 )
        	return notify_fail("²»ÊÇÕÆÃÅÈË²»¿ÉÊÕÍ½£®\n");
        	
    	if((string)me->query("family/family_name") ==(string)ob->query("family/family_name"))
        if((int)me->query("family/generation") <= (int)ob->query("family/generation"))
            	return notify_fail(ob->name()+"µÄ±²·Ö²¢²»±ÈÄã¸ß£¡\n");
    
    	score_cost = ob->query("score_cost") ? ob->query("score_cost") : 1000;
    	if (!me->query("family")
    		|| me->query("family/family_name") == ob->query("family/family_name")) 
    		score_cost = 0;
    	
    	if (me->query("score")< score_cost) {
    		message_vision("$NËµ£ºÄãµÄÉùÍûÌ«²î£¬ÎÒ²»ÏëÊÕÄãÎªÍ½£¨ÖÁÉÙĞèÒª"+score_cost+"ÆÀ¼Û£©\n",ob);
    		return 1;
    	}
    	
    	if (!ob->query("class"))
    		return notify_fail("ÇëÍ¨ÖªÎ×Ê¦¸Ä½ø´ËNPC¡£\n");
    	
    	if (me->query("once_menpai"))
    	if (member_array(ob->query("class"), keys(me->query("once_menpai")))!=-1
    		&& me->query("family/family_name")!= ob->query("family/family_name")
    	    	) {
    		message_vision("$NËµ£ºÄã¼ÈÈ»ÒÑ¾­²»ÈÏÎÒÕâ¸öÊ¦¸µÁË£¬»¹»ØÀ´×öÊ²Ã´£¿\n",ob);
    		return 1;
    	}
    	
/*    	if (me->query("family") && !me->query_temp("marks/apprentice_others")
    		&& me->query("family/family_name")!= ob->query("family/family_name")) {
    		message_vision("$NËµ£º½­ºşÖĞÈË£¬×îÖØÊ¦Í½Ö®Òå£¬Äã»¹ÊÇÏÈºÍÄãÊ¦¸µ½»´úÒ»ÏÂ°É¡£\n",ob);
    		return 1;
    	}						-- So many troubles */
    	 
/*
		A ÀÏÊ¦£¬ B ĞÂÉú

		A recruit B, B apprentice, Ö»Òª²»ÊÇÍ¬ÃÅ£¬²¢ÇÒB²»ÊÇ°ÙĞÕ£¬B¾ÍËãÊÇÅÑÊ¦£¬¿ÛBµÄscore
		B apprentice A, A recruit, Ö»Òª²»ÊÇÍ¬ÃÅ£¬²¢ÇÒB²»ÊÇ°ÙĞÕ£¬¾ÍËãÊÇÅÑÊ¦£¬¿ÛBµÄscore

*/ 
    	   		   	
    // If the target is willing to recruit us already, we do it.
    	if( (object)ob->query_temp("pending/recruit") == me )
    	{
        	if( mapp(me->query("family")) &&
        			(string)me->query("family/family_name") !=(string)ob->query("family/family_name") 
        			&& (string)me->query("family/title") !="ÆúÍ½")
        	{
	            	message_vision("$N¾ö¶¨±³ÅÑÊ¦ÃÅ£¬¸ÄÍ¶Èë$nÃÅÏÂ£¡£¡\n\n"
	                	"$N¹òÁËÏÂÀ´Ïò$n¹§¹§¾´¾´µØ¿ÄÁËËÄ¸öÏìÍ·£¬½ĞµÀ£º¡¸Ê¦¸¸£¡¡¹\n\n",me, ob);
	            	if(me->query("score") > score_cost) 
	            		me->add("score", -score_cost);
	            	else
	            		me->set("score",0);
	            	me->add("betrayer", 1);
        	}
        	else message_vision("$N¾ö¶¨°İ$nÎªÊ¦¡£\n\n"
                	"$N¹òÁËÏÂÀ´Ïò$n¹§¹§¾´¾´µØ¿ÄÁËËÄ¸öÏìÍ·£¬½ĞµÀ£º¡¸Ê¦¸¸£¡¡¹\n\n",me, ob);

        	ob->recruit_apprentice(me);
        	ob->delete_temp("pending/recruit");
			me->delete_temp("marks/apprentice_others");
				
        	tell_object(ob, "¹§Ï²ÄãĞÂÊÕÁËÒ»ÃûµÜ×Ó£¡\n");
        	family = me->query("family");
        	printf("¹§Ï²Äú³ÉÎª%sµÄµÚ%s´úµÜ×Ó¡£\n", me->query("family/family_name"),
               		chinese_number( me->query("family/generation")));
			return 1;
	
    	} else {
           	
           	old_app = me->query_temp("pending/apprentice");
        	if( ob==old_app )
            	return notify_fail("ÄãÏë°İ" + ob->name() +"ÎªÊ¦£¬µ«ÊÇ¶Ô·½»¹Ã»ÓĞ´ğÓ¦¡£\n");
        	else if ( objectp(old_app) ) {
            	write("Äã¸Ä±äÖ÷Òâ²»Ïë°İ" + old_app->name() + "ÎªÊ¦ÁË¡£\n");
            	tell_object(old_app, me->name() + "¸Ä±äÖ÷Òâ²»Ïë°İÄãÎªÊ¦ÁË¡£\n");
        	}
		
			message_vision("$NÏëÒª°İ$nÎªÊ¦¡£\n", me, ob);
        	me->set_temp("pending/apprentice", ob );
        	if( userp(ob) ) {
            	tell_object(ob, YEL "Èç¹ûÄãÔ¸ÒâÊÕ" + me->name()+"ÎªµÜ×Ó£¬ÓÃ recruit Ö¸Áî¡£\n" NOR);
        	} else 
            	ob->attempt_apprentice(me);
	        return 1;
    	}
}


int help(object me)
{
    write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : apprentice [cancel]|<¶ÔÏó>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
Õâ¸öÖ¸ÁîÄÜÈÃÄã°İÄ³ÈËÎªÊ¦£¬Èç¹û¶Ô·½Ò²´ğÓ¦ÒªÊÕÄãÎªÍ½µÄ»°£¬¾Í»áÁ¢¼´ĞĞ
°İÊ¦Ö®Àñ£¬·ñÔòÒªµÈµ½¶Ô·½ÓÃ recruit Ö¸ÁîÊÕÄãÎªµÜ×Ó²ÅÄÜÕıÊ½°İÊ¦¡£

Çë×¢ÒâÄãÒÑ¾­ÓĞÁËÊ¦¸¸£¬ÓÖ±³ÅÑÊ¦ÃÅÍ¶Èë±ğÈËÃÅÏÂ£¬Ã¿ÅÑÒ»´Î£¬ÔÚĞÂÊ¦¸µÃÅ
ÏÂÄÜÑ§µ½µÄËùÓĞ¼¼ÄÜµÈ¼¶»á¼õÉÙ20¼¶£¬²¢ÇÒÆÀ¼ÛÖÁÉÙ»á½µµÍ1000µã¡£Èç¹ûÄã
µÄÆÀ¼ÛµÍÓÚ1000µã£¬´ó²¿·ÖÃÅÅÉÊÇ²»»á½ÓÊÜÄãÅÑÊ¦µÄ¡£

µ±È»£¬½­ºşÖĞÒ²ÓĞÒ»²¿·ÖÊ¦¸µ²»ÔÚºõÄãÊÇ·ñÅÑ¹ıÊ¦¡£

Èç¹û¶ÔÄãµÄÊ¦¸¸Ê¹ÓÃÕâ¸öÖ¸Áî£¬»á±ä³ÉÏòÊ¦¸¸Çë°²£¬²¢ÒªÇóÊ¦¸¸¸øÄã¸öºÏÊÊ
µÄ³ÆºÅ¡£
 
Çë²Î¿¼Ïà¹ØÖ¸Áî expell¡¢recruit
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
HELP
        );
    return 1;
}

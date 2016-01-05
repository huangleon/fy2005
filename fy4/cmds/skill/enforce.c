// enforce.c
// the maxium 150 enforce is added for game balance. Silencer @1-1-2002

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int pts;

        if( !arg || (arg!="none" && !sscanf(arg, "%d", pts)) ) 
                return notify_fail("÷∏¡Ó∏Ò Ω£∫enforce < π≥ˆº∏≥…ƒ⁄¡¶…Àµ–>|none");

        if( !me->query_skill_mapped("force") )
                return notify_fail("ƒ„±ÿ–Îœ» enable “ª÷÷ƒ⁄π¶°£\n");

        if( arg=="none" )
                me->delete("force_factor");
        else {
                if( pts < 0 || pts > (int)me->query_skill("force")/3)
                        return notify_fail("ƒ„µƒƒ⁄π¶Œﬁ∑®∑¢ª”’‚√¥¥ÛµƒÕ˛¡¶°£\n");
                if (pts >150)
                	return notify_fail("Enforce ◊Ó¥Û»›–Ì÷µ «150°£\n");
                me->set("force_factor", pts);
        }

        write("Ok.\n");
        return 1;
}

int help (object me)
{
        write(@HELP
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m
[0;1;36m÷∏¡Ó∏Ò Ω : 	enforce < π≥ˆº∏µ„ƒ⁄¡¶…Àµ–>|none[0m
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m   
 
’‚∏ˆ÷∏¡Ó»√ƒ„÷∏∂®√ø¥Œª˜÷–µ–»À ±£¨“™∑¢≥ˆº∏µ„ƒ⁄¡¶…Àµ–°£
ƒ⁄¡¶‘Ω∏ﬂ£¨∂‘µ–»Àµƒ…À∫¶‘Ω¥Û°£

enforce none ‘Ú±Ì æƒ„≤ª π”√ƒ⁄¡¶°£ 

∑Á‘∆2005÷–◊Ó∏ﬂ enforce÷µŒ™150°£
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m   
HELP
        );
        return 1;
}
 

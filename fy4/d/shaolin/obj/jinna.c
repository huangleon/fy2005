inherit "/d/fycycle/obj/tutor";

void create()
{
        set_name("������", ({"������","jinnaluo","jinna"}));    
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
                        "�ֳ������Ľ����ޡ�\n");
 		set("no_shown", 1);
 		set("no_get",1);
 		set("teaching", "xingyi-stick");
 		set("teaching_limit", 100);
 	}
 	
 }
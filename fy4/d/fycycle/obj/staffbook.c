inherit __DIR__"tutor";

void create()
{
        set_name("����", ({ "caoren","����" }));    
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
                        "һ��âЬ���ȵĲ��ˡ�����������ƺ���֧�������壬���ƺ��ǲ�����������档\n");
 		set("no_shown", 1);
 		set("no_get",1);
 		set("teaching", "staff");
 		set("teaching_limit", 400);
 	}
 	
 }

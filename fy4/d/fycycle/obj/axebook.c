inherit __DIR__"tutor";

void create()
{
        set_name("���츫", ({ "axe","���츫" }));    
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
                        "һ��Ƕ�����е�ǽ�ڵĿ��츫��һ��֮�Ʋ����κα仯��ȴ�зָ����֮����\n");
 		set("no_shown", 1);
 		set("no_get",1);
 		set("teaching", "axe");
 		set("teaching_limit", 400);
 	}
 	
 }
